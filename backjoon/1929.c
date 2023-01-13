#include <stdio.h>

// 소수 구하기

int main() {
	int M, N, arr[1000001];
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N + 1; i++) {
		arr[i] = 1;
	}

	arr[1] = 0;
	for (int i = 2; i < N + 1; i++) {
		for (int j = i * 2; j < N + 1; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = M; i < N + 1; i++) {
		if (arr[i] == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}

// 에라토스테네스의 체
// 1. 소수를 구할 경우 주어진 최대값까지 배열요소를 1로 초기화
// 2. i=2부터 시작해 2중 for문을 돌면서 i의 배수를 0으로 변경
// 3. 배열의 요소가 아닌 배열의 인덱스가 소수가 됨