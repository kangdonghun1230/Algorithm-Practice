#include <iostream>
#include <vector>
#include <queue>

#define MAX 20001

using namespace std;

vector<int> m[MAX];
int visited[MAX] = { 0, };

bool BFS(int idx) {
	queue<int> q;
	q.push(idx);

	visited[idx] = 1;

	while (!q.empty()) {
		int x = q.front();
		int cur = visited[x];
		q.pop();

		for (int i = 0; i < m[x].size(); i++) {
			int y = m[x][i];
			// 현재 칸의 구분자가 1이면 2, 2이면 1로 할당
			int next = (cur == 1) ? 2 : 1;

			// 다음 칸의 구분자가 이미 작성되어 있고, 현재 칸의 구분자와 같다면
			if (visited[y] == cur)
				return false;
			// 다음 칸의 구분자가 이미 잘 작성된 경우 건너 띈다.
			if (visited[y] == next)
				continue;

			visited[y] = next;
			q.push(y);
		}
	}
	// 위 과정에서 별 이상이 없었던 경우 bipartite graph라고 할 수 있다.
	return true;
}

void init() {
	for (int i = 1; i < MAX; i++) {
		m[i].clear();
		visited[i] = 0;
	}
	return;
}

int main() {
	int t;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		int v, e;

		cin >> v >> e;

		init(); // vector 내의 모든 요소를 비운다.

		for (int i = 0; i < e; i++) {
			int sta, end;

			cin >> sta >> end;

			m[sta].push_back(end);
			m[end].push_back(sta);
		}

		bool isBipartite = true;

		for (int i = 0; i < v; i++) {
			if (visited[i] != 0)
				continue;
			if (!BFS(i))
				isBipartite = false;
		}
		cout << (isBipartite ? "YES\n" : "NO\n");
	}
	return 0;
}