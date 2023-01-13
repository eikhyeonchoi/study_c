#include <stdio.h>
#include <stdlib.h>

// 소수

int isPrime(int);

int main() {
	int M, N;
	int sum = 0;
	int min = 0;
	scanf("%d%d", &M, &N);

	for (int i = N; i > M - 1; i--) {
		int prime = isPrime(i);
		if (prime) sum += i;
		if (sum != 0 && prime) min = i;
	}

	if (sum == 0 || min == 0) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", sum);
		printf("%d\n", min);
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