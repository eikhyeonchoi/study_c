#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = -1;

bool isFull(void);
bool isEmpty(void);
int push(int data);
int pop(void);
void show(void);

int main() {
	int m = 0;
	while (1) {
		printf("-----------------------\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. show\n");
		printf("-----------------------\n");
		printf("select ==> ");
		scanf_s("%d", &m);

		if (m == 1) {
			int data = 0;
			printf("push data ? => ");
			scanf_s("%d", &data);
			int result = push(data);
			if (result == -1) {
				printf("stack is full !! \n");
			}
			show();
		}
		else if (m == 2) {
			int data = pop();
			if (data != -1) {
				printf("pop data = %d\n", data);
			}
			else {
				printf("stack is empty !! \n");
			}
		}
		else if (m == 3) {
			show();
		}
		else {
			break;
		}
	}

	return 0;
}

bool isFull(void) {
	return (top - 1) == STACK_SIZE;
}

bool isEmpty(void) {
	return top == -1;
}

int push(int data) {
	if (isFull()) {
		return -1;
	}
	stack[++top] = data;
	return data;
}

int pop(void) {
	if (isEmpty()) {
		return -1;
	}
	int data = stack[top];
	stack[top] = NULL;
	top--;

	return data;
}

void show(void) {
	if (!isEmpty()) {
		for (int i = STACK_SIZE; i > -1; i--) {
			if (stack[i]) {
				printf("%d층 = %d\n", i+1, stack[i]);
			}
			else {
				printf("%d층 = [empty]\n", i + 1);
			}
			
		}
	}
}