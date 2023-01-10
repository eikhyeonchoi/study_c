#include <stdio.h>
#include <stdlib.h>

// 기본 오름차순 정렬

typedef struct Node {
	int data;
	Node* next;
};

typedef struct LinkedList {
	Node* head;
	int count;
};

LinkedList* l;

void initLinkedList();
bool isEmpty();
void insertData(int data);
int deleteData(int data);
int searchList(int data);
void showList();

int main() {
	initLinkedList();
	int m = 0;
	while (1) {
		printf("-------------------------------\n");
		printf("1. insert \n");
		printf("2. delete \n");
		printf("3. search \n");
		printf("4. show \n");
		printf("5. count \n");
		printf("-------------------------------\n");
		printf("select ==> ");
		scanf_s("%d", &m);

		if (m == 1) {
			int value = 0;
			printf("insert data ?? ==> ");
			scanf_s("%d", &value);

			insertData(value);
			showList();
		} else if (m == 2) {
			int value = 0;
			printf("delete data ?? ==> ");
			scanf_s("%d", &value);

			deleteData(value);
			showList();
		} else if (m == 3) {
			int value = 0;
			printf("search data ?? ==> ");
			scanf_s("%d", &value);

			searchList(value);
			showList();
		} else if (m == 4) {
			showList();
		} else if (m == 5) {
			printf("%d", l->count);
		} else {
			break;
		}

		
	}

	return 0;
}

void initLinkedList() {
	l = (LinkedList*)malloc(sizeof(LinkedList));
	l->head = NULL;
	l->count = 0;
}

bool isEmpty() {
	return l->head == NULL && l->count == 0;
}

void insertData(int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;

	l->count++;

	if (l->head == NULL) {
		l->head = n;
		return;
	}

	if (l->head->data > n->data) {
		n->next = l->head;
		l->head = n;
		return;
	}

	Node* temp;
	temp = l->head;
	while (temp->next) {
		if (temp->data < n->data && temp->next->data > n->data) {
			n->next = temp->next;
			temp->next = n;
			return;
		}

		temp = temp->next;
	}

	temp->next = n;
	
}

int deleteData(int data) {
	Node* prev, * cur;
	prev = cur = l->head;

	if (isEmpty()) {
		printf("!!! empty list !!!\n");
		return -1;
	}

	if (l->head->data == data) {
		l->head = cur->next;
		free(cur);
		l->count--;
		return data;
	}

	while (cur->next) {
		cur = cur->next;
		if (cur->data == data) {
			prev->next = cur->next;
			free(cur);
			l->count--;
			return cur->data;
		}
		prev = cur;
	}

	printf("no data\n");
	return -1;
}

int searchList(int data) {
	Node* n = l->head;
	while (n->next) {
		if (n->data == data) {
			return n->data;
		}
		n = n->next;
		//if (!n->next) {
		//	if (n->next->data == data) {
		//		return n->next->data;
		//	}
		//}
	}

	printf("no data\n");
	return -1;
}

void showList() {
	Node* n = l->head;
	while (n->next) {
		printf("%d->", n->data);
		n = n->next;
	}
	printf("%d\n", n->data);
}