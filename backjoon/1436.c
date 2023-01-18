#include <stdio.h>

// 영화감독 숌

int main() {
	int N, num = 666, cnt = 0;
	scanf("%d", &N);

	while (cnt != N) {
		int copy = num;
		while (copy != 0) {
			if (copy % 1000 == 666) {
				cnt++;
				break;
			}
			copy /= 10;
		}
		num++;
	}

	printf("%d", num - 1);
	return 0;
}
