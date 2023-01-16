#include <stdio.h>
#define N 100
#define M 10

// 색종이

int main() {
	int arr[N][N] = { 0, };
	int t, sum = 0;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int v, h;
		scanf("%d %d", &v, &h);

		for (int j = v-1; j < M + v - 1; j++) {
			for (int k = h-1; k < M + h - 1; k++) {
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				sum += 1;
			}
		}
	}

	printf("%d", sum);
	return 0;
}