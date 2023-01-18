#include <stdio.h>

int main() {
	int N, min = 0, constructor;
	scanf("%d", &N);

	constructor = N;
	while (1) {
		if (constructor == 0) {
			if (min != 0) constructor = min;
			break;
		}

		int sum = 0, remain = constructor;
		while (remain > 9) {
			sum += remain % 10;
			remain /= 10;
		}
		sum += remain;

		if (constructor + sum == N) {
			min = constructor;
		}

		constructor--;
	}

	printf("%d\n", constructor);
	return 0;
}
