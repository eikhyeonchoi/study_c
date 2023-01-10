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

Node* deleteNode(Node* node, int key) {
	Node* parent = NULL;
	Node* del = node;
	while (del) {
		if (del->val == key) {
			break;
		}

		parent = del;
		if (del->val > key) {
			del = del->left;
		}
		else {
			del = del->right;
		}
	}

	if (!del) {
		printf("no node\n");
		return NULL;
	}

	// 단말노드일경우 단순 삭제
	if (!(del->right) && !(del->left)) {
		if (parent) {
			if (parent->left == del) {
				parent->left = NULL;
			} else {
				parent->right = NULL;
			}
		} else {
			node = NULL;
		}
	}

	// 자식노드가 하나일경우
	if (!(del->right) || !(del->left)) {
		Node* child = del->left;
		if (!del->left) {
			child = del->right;
		}

		if (parent) {
			if (parent->left == del) {
				parent->left = child;
			} else {
				parent->right = child;
			}
		} else {
			node = child;
		}
	}

	// 자식노드가 2개일 경우
	if (del->left && del->right) {
		Node* leftParent = del;
		Node* leftChild = del->left;

		while (leftChild->right) {
			leftParent = leftChild;
			leftChild = leftChild->right;
		}

		leftParent->right = leftChild->left;
		leftChild->left = node->left;
		leftChild->right = node->right;

		if (parent) {
			if (parent->left == del) {
				parent->left = leftChild;
			} else {
				parent->right = leftChild;
			}
		} else {
			node = leftChild;
		}
	}

	free(del);
	return node;
}
