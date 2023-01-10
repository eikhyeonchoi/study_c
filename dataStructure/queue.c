#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* next;
};

typedef struct Queue {
	Node* front;
	Node* rear;
	int count;
};

void initQueue(Queue* q);
bool isEmpty(Queue* q);
void enq(Queue* q, int data);
int deq(Queue* q);

int main() {
	Queue q;
	initQueue(&q);
	for (int i = 0; i < 10; i++) {
		enq(&q, i + 100);
	}

	Node* check = q.front;
	while (check->next != NULL) {
		printf("%d", check->data);
		check = check->next;
	}
	return 0;
}

void initQueue(Queue* q) {
	q->front = q->rear = NULL;
	q->count = 0;
}

bool isEmpty(Queue* q) {
	return q->count == 0;
}

void enq(Queue* q, int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;

	if (isEmpty(q)) {
		q->front = n;
	} else {
		q->rear->next = n;
	}

	q->rear = n;
	q->count++;
}

int deq(Queue* q) {
	if (isEmpty(q)) {
		printf("!!! empty queue !!! \n");
		return 0;
	}

	Node* temp;
	int data;
	temp = q->front;
	data = temp->data;
	q->front = temp->next;

	free(temp);
	q->count--;

	return data;
}
