/*
* @brief about traversal of binary tree (data structure)
* @date 2021/08/20
* @author 강동훈
* @parameter nothing
* @return nothing
*/
#include <iostream>
#define num 15
using namespace std;


typedef struct node* treePointer;

typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[num + 1];

	for (int i = 1; i <= num; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= num; i++) {
		// left child
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		// right child
		if (i % 2 == 1) {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	cout << "preorder" << endl;
	preorder(&nodes[1]);
	cout << endl;

	cout << "inorder" << endl;
	inorder(&nodes[1]);
	cout << endl;

	cout << "postorder" << endl;
	postorder(&nodes[1]);
	cout << endl;

	return 0;
}
/*
binary tree의 3가지 순회 방식에 대해서 알아보았다.
전위 순회, 중위 순회, 후위 순회 (각 순회의 이름은 
본인 노드를 방문하는 우선순위에 따라 지어진 것 같다.)
*/