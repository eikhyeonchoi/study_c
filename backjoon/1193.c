#include <stdio.h>

// 1193 분수찾기

int main() {
	int n = 0;
	scanf("%d", &n);

	int i = 1;
	while (n > i) {
		n -= i;
		i++;
	}

	if (i % 2 == 0) {
		printf("%d/%d", n, i + 1 - n);
	} else {
		printf("%d/%d", i + 1 - n, n);
	}

	return 0;
}