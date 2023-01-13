#include <stdio.h>
#define SIZE 123456 * 2 + 1

// 베르트랑 공준

int main() {
	int N, arr[SIZE];
	int sum = 0;
	
	while (1) {
		sum = 0;
		scanf("%d", &N);
		if (N == 0) break;

		for (int i = 0; i < 2 * N + 1; i++) {
			arr[i] = 1;
		}

		arr[1] = 0;
		for (int i = 2; i < 2 * N + 1; i++) {
			for (int j = 2; i * j < 2 * N + 1; j++) {
				arr[i * j] = 0;
			}
		}

		for (int i = N + 1; i < 2 * N + 1; i++) {
			if (arr[i] == 1) {
				sum += 1;
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}

// 