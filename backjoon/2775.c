#include <stdio.h>
int getn(int, int);
int main() {
	int t, k, n;
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%d", &k);
		scanf_s("%d", &n);
		printf("%d\n", getn(k, n));
	}
	return 0;
}

int getn(int k, int n) {
	if (k == 0) return n;
	if (n == 1) return 1;
	return getn(k - 1, n) + getn(k, n - 1);
}