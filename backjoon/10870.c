#include <stdio.h>

// 피보나치 수 5

int p(int);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", p(n));
	return 0;
}

int p(int a) {
	if (a == 0 || a == 1) return a;
	return p(a - 1) + p(a - 2);
}