#include <stdio.h>
#define N 9

// 최댓값

int main() {
	int max, maxi, maxj, i, j;
	max = maxi = maxj = i = j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int a;
			scanf("%d", &a);
			if (max < a) {
				max = a;
				maxi = i;
				maxj = j;
			}
		}
	}

	printf("%d\n", max);
	printf("%d %d\n", maxi + 1, maxj + 1);
	return 0;
}
