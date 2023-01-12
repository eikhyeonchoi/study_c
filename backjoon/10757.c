#include <stdio.h>
#include <string.h>

// 큰 수 A+B

void reverse(char[]);

int main() {
	char a[10002] = { 0 };
	char b[10002] = { 0 };
	char c[10003] = { 0 };
	int carry = 0;
	scanf("%s %s", a, b);

	reverse(a);
	reverse(b);

	int len = strlen(a);
	if (len < strlen(b)) {
		len = strlen(b);
	}

	for (int i = 0; i < len; i++) {
		int sum = a[i] - '0' + b[i] - '0' + carry;
		if (sum < 0) sum += '0';

		if (sum > 9) {
			carry = 1;
		} else {
			carry = 0;
		}
		c[i] = sum % 10 + '0';
	}

	if (carry == 1) {
		c[len] = '1';
	}

	reverse(c);
	printf("%s", c);
	return 0;
}

void reverse(char a[]) {
	int size = strlen(a);
	for (int i = 0; i < size / 2; i++) {
		char temp = a[i];
		a[i] = a[size - 1 - i];
		a[size - 1 - i] = temp;
	}
}
