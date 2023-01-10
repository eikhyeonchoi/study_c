#include <stdio.h>
#include <stdlib.h>

// 참고
// https://code-lab1.tistory.com/10

typedef struct _Node {
	int val;
	struct _Node* left;
	struct _Node* right;
}Node;

Node* search(Node*, int);
Node* insert(Node*, int);

int main() {
	Node* root = NULL;

	return 0;
}

Node* search(Node* node, int key) {
	if (!node) {
		printf("empty tree\n");
		return NULL;
	}

	if (node->val == key) {
		return node;
	}

	if (node->val < key) {
		return search(node->right, key);
	}
	else {
		return search(node->left, key);
	}
}

Node* insert(Node* node, int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = key;
	newNode->left = newNode->right = NULL;

	if (!node) {
		node = newNode;
		return node;
	}

	Node* ptr = node;
	while (ptr) {
		if (ptr->val == key) {
			printf("중복된 value = '%d'\n", key);
			return node;
		}

		if (ptr->val < key) {
			if (ptr->right) {
				ptr = ptr->right;
			}
			else {
				ptr->right = node;
				return node;
			}
		}
		else {
			if (ptr->left) {
				ptr = ptr->left;
			}
			else {
				ptr->left = node;
				return node;
			}
		}
	}
}