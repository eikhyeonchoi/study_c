#include <stdio.h>

// 소인수분해

int isPrime(int);

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 2; i < N + 1; i++) {
		if (N % i == 0 && isPrime(i)) {
			printf("%d\n", i);
			N = N / i;
			i--;
		}
	}
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