#include <stdio.h>
#include <stdlib.h>

// 정렬

void quicksort(int[], int, int);

int main() {
	int N;
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		*(arr + i) = k;
	}

	quicksort(arr, 0, N-1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

    free(arr);
	return 0;
}

void quicksort(int arr[], int L, int R) {
	int pivot = arr[(L + R) / 2];
	int left = L;
	int right = R;

	do {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);

	if (L < right) {
		quicksort(arr, L, right);
	}

	if (R > left) {
		quicksort(arr, left, R);
	}
}