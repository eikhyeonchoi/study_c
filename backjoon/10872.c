#include <stdio.h>

// 팩토리얼

int f(int);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
	return 0;
}

int f(int a) {
	if (a == 0) return 1;
	return a * f(a - 1);
}