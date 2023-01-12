#include <stdio.h>

// 2839 설탕배달

int main() {
	int N = 0;
	int answer = 0;
	scanf_s("%d", &N);

	while (N >= 0) {
		if (N % 5 == 0) {
			answer += N / 5;
			printf("%d", answer);
			return 0;
		}

		N -= 3;
		answer++;
	}

	printf("-1");
	return 0;
}