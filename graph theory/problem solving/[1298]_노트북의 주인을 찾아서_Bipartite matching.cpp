#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int n, m;
int d[MAX];
bool c[MAX];

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		// note book number
		int y = a[x][i];
		
		// pass already checked notebook
		if (c[y]) continue;
		c[y] = true;

		// notebook owner is empty or changable owner
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			// matching success
			return true;
		}
	}
	// matching fail
	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		a[x].push_back(y);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
