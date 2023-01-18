#include <stdio.h>
#include <stdlib.h>

// 블랙잭

int main() {
	int N, M, sum = 0, *arr;
	scanf("%d%d", &N, &M);

	arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				int blackjack = arr[i] + arr[j] + arr[k];
				if (sum < blackjack && M >= blackjack) {
					sum = blackjack;
				}
			}
		}
	}

	printf("%d\n", sum);
	free(arr);
	return 0;
}
