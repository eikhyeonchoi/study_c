#include <stdio.h>
#include <stdlib.h>

// 행렬 덧셈

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int** arr;
	arr = (int**)malloc(sizeof(int*) * (n * 2));

	for (int i = 0; i < n * 2; i++) {
		*(arr + i) = (int*)malloc(sizeof(int) * m);
	}

	// 입력
	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < m; j++) {
			int ss;
			scanf("%d", &ss);
			*(*(arr + i) + j) = ss;
		}
	}

	// 더하기(덮어쓰기)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(*(arr + i) + j) += *(*(arr + i + n) + j);
		}
	}

	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}

	for (int i = 0; i < n*2; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}

// 이중포인터 사용
// malloc -> free 습관화할 것