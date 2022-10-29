#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

bool visited[MAX];
int dis[MAX];
int cnt = 1;
int n, m, r;
vector<int> v[MAX];

void dfs(int start) {
	int x = start;
	dis[x] = cnt++;
	
	for (int i = v[x].size() - 1; i >= 0; i--) {
		int y = v[x][i];

		if (dis[y])
			continue;
		
		dfs(y);
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int sta, end;
		cin >> sta >> end;

		v[sta].push_back(end);
		v[end].push_back(sta);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n; i++) {
		cout << dis[i] << '\n';
	}

	return 0;
}