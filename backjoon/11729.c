#include <stdio.h>
#include <math.h>

// 하노이

void hanoi(int, int, int, int);

int main() {
	int n;
	scanf("%d", &n);

	printf("%.0f\n", pow(2.0, (double)n) - 1);
	hanoi(n, 1, 2, 3);
	return 0;
}

void hanoi(int n, int start, int mid, int end) {
	if (n == 1) {
		printf("%d %d\n", start, end);
		return;
	}

	// 1. start에 있는 n-1개의 원판을 end -> mid
	hanoi(n - 1, start, end, mid);

	// 2. start에 있는 원판을 end로
	printf("%d %d\n", start, end);

	// 3. mid에 있는 n-1개의 원판을 start->end
	hanoi(n - 1, mid, start, end);
}

// 하노이 공식
// 원판을 옮긴 횟수 2^n - 1
// 원판 옮기는 순서 -> 주석참고(단계별)