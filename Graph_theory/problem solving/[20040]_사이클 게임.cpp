/*
	Date: 2022/03/11
	Brief:
	simple union find problem. checking cycle in graph.
	Reference:
*/
#include <iostream>
#define MAX 500001

using namespace std;

int parent[MAX];

int getParent(int x) {
	if (x == parent[x]) return parent[x];
	else return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool checkParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x == y) return true;
	else return false;
}


int main() {
	int n, m;
	int i;
	cin.tie(NULL);
	cin >> n >> m;

	for (i = 0; i <= n; i++) {
		parent[i] = i;
	}


	for (i = 0; i < m; i++) {
		int x, y;

		cin >> x >> y;
		if (checkParent(x, y)) {
			cout << i + 1 << "\n";
			return 0;
		}
		unionParent(x, y);
	}

	cout << "0\n";

	return 0;
}