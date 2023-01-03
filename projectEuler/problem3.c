#include <stdio.h>
#include <math.h>
/*
The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int sumOfSquare(int);
int squareOfSum(int);

int main() {
	printf("%d", squareOfSum(100) - sumOfSquare(100));
	return 0;
}

int sumOfSquare(int until) {
	int sum = 0;
	for (int i = 1; i <= until; i++) {
		sum += pow(i, 2);
	}

	return sum;
}

int squareOfSum(int until) {
	int sum = 0;
	for (int i = 1; i <= until; i++) {
		sum += i;
	}

	return pow(sum, 2);
}
