#include <stdio.h>
#define N 5

// 대표값2

void quicksort(int[], int, int);

int main() {
	int arr[N] = { 0, };
	int sum = 0;
	int avg = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}

	quicksort(arr, 0, N - 1);
	printf("%d\n%d\n", sum / N, arr[N / 2]);
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