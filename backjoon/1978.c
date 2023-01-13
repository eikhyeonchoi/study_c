#include <stdio.h>
#include <stdlib.h>

// 소수찾기

int isPrime(int);

int main() {
	int N;
	int sum = 0;
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", (arr + i));
		if (isPrime(*(arr + i))) {
			sum++;
		}
	}

	printf("%d\n", sum);
	return 0;
}

int isPrime(int a) {
	if (a == 1) return 0;
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}