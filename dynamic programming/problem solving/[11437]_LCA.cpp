#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 50001
#define LOG 16 /* 2^16개 이하의 전체노드를 가집니다.*/

using namespace std;

int n, m, parent[MAX][LOG], d[MAX]; /* node, distance want to know, parent info, depth info */
bool c[MAX]; /* checking visited or not */
vector<int> a[MAX]; /* graph info */

void dfs(int x, int depth) {
	d[x] = depth;
	c[x] = true;

	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;
		// y's 1st parent = x
		parent[y][0] = x;
		// call dfs recursively to setup depth info
		dfs(y, depth + 1);
	}
	return;
}

void setParent() {
	// setting depth info
	dfs(1, 0);

	// parent[n][0] is already initialized
	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= n; j++) {
			// i-1 th parent't i-1 th parent = i th parent
			int tmp = parent[j][i - 1];
			parent[j][i] = parent[tmp][i - 1];
		}
	}
	return;
}

int LCA(int x, int y) {
	// set deeper depth to y
	if (d[x] > d[y]) {
		swap(x, y);
	}
	// make two node's depth same
	for (int i = LOG - 1; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			// move to i th parent
			y = parent[y][i];
		}
	}
	// if reach to same node (same depth same parent)
	if (x == y) return x;

	for (int i = LOG - 1; i >= 0; i--) {
		// move to last node(where two node's parents are different)
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	// finally reach to same parent's first child node
	return parent[x][0];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}

	setParent();

	scanf("%d", &m);
	vector<int> result;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		int num = LCA(x, y);
		result.push_back(num);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}