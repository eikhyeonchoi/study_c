#include <stdio.h>
#include <stdlib.h>

// 연습문제 퀵정렬

void quicksort(int[], int, int);

int main() {
	int len = 0;
	printf("정렬할 갯수 : ");
	scanf("%d", &len);

	int* arr = (int*)malloc(sizeof(int) * 4);

	for (int i = 0; i < len; i++) {
		printf("%d번째 수 : ", i + 1);
		scanf("%d", (arr + i));
		printf("\n");
	}

	quicksort(arr, 0, len - 1);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void quicksort(int arr[], int L, int R) {
	int pivot = arr[(L + R) / 2], left = L, right = R;
	int temp;
	
	do {
		while (pivot > arr[left]) left++;
		while (pivot < arr[right]) right--;
		if (left <= right) {
			temp = arr[left];
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