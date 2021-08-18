/*
* @brief union find algorithm
* @date 2021/08/18
* @author 강동훈
* @parameter nothing
* @return nothing
*/
#include <iostream>

using namespace std;

// get the parent of node x
int getParent(int parent[], int x) {
	// x is root node
	if (parent[x] == x) return x;
	// call getParent function recursively to find parent of current node x
	return parent[x] = getParent(parent, parent[x]);
}

// union the parent node of two nodes
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool checkParent(int parent[], int a, int b) {
	// find the parent of two nodes
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return true;
	else return false;
}

int main() {
	int parent[11];

	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	cout << "1과 5는 연결되어 있나요?" << endl;
	if (checkParent(parent, 1, 5))
		cout << "네" << endl;
	else
		cout << "아니오" << endl;

	return 0;
}