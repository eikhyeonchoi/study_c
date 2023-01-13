#include <stdio.h>
#include <stdlib.h>
#define SIZE 10001

// 골드바흐의 추측

void get_prime(int[]);
int main() {
	int T;
	int arr[SIZE] = { 0 };
	scanf("%d", &T);

	get_prime(arr);
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);

		int p1 = n / 2;
		int p2 = n / 2;
		while (1) {
			if (arr[p1] && arr[p2]) {
				break;
			}

			p1--;
			p2++;
		}

		printf("%d %d\n", p1, p2);
	}

	return 0;
}

void get_prime(int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		*(arr + i) = 1;
	}

	*(arr) = 0;
	*(arr + 1) = 0;

	for (int i = 2; i < SIZE; i++) {
		for (int j = 2; i * j < SIZE; j++) {
			*(arr + (i * j)) = 0;
		}
	}
}

// 매번 prime을 검사하는게 아니라
// size 10000의 배열을 아리스토테네스의 체 알고리즘으로 prime array를 구해놓고
// prime 판별을 해야 속도를 만족할 수 있다