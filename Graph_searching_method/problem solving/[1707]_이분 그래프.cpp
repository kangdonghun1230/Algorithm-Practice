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
			// ���� ĭ�� �����ڰ� 1�̸� 2, 2�̸� 1�� �Ҵ�
			int next = (cur == 1) ? 2 : 1;

			// ���� ĭ�� �����ڰ� �̹� �ۼ��Ǿ� �ְ�, ���� ĭ�� �����ڿ� ���ٸ�
			if (visited[y] == cur)
				return false;
			// ���� ĭ�� �����ڰ� �̹� �� �ۼ��� ��� �ǳ� ���.
			if (visited[y] == next)
				continue;

			visited[y] = next;
			q.push(y);
		}
	}
	// �� �������� �� �̻��� ������ ��� bipartite graph��� �� �� �ִ�.
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

		init(); // vector ���� ��� ��Ҹ� ����.

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