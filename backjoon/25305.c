#include <stdio.h>
#include <stdlib.h>

// 커트라인

void quicksort(int[], int, int);

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	quicksort(arr, 0, n - 1);
	printf("%d\n", arr[n - k]);
	free(arr);
	return 0;
}

void quicksort(int arr[], int L, int R) {
	int pivot = arr[(L + R) / 2], left = L, right = R;

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

	if (L < right) quicksort(arr, L, right);
	if (R > left) quicksort(arr, left, R);
}