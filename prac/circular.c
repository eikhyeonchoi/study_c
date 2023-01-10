#include <stdio.h>

// 연습문제 회문
int main() {
	char string[30];
	scanf("%s", string);

	int s = 0;
	int l = 0;
	while (string[l] != '\0') {
		l++;
	}

	for (int i = 0; i < l; i++) {
		if (*(string + s) != *(string + l - 1)) {
			printf("x");
			break;
		}
	}

	printf("o");
	return 0;
}