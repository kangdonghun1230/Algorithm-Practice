#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 100001
using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;
// �� �������� � �׷쿡 ���ϴ����� �˱� ���ؼ�
int group[MAX];
bool inDegree[MAX];

int dfs(int x) {
	// ������ id�� �Ҵ��ϰ� stack�� �־��ݴϴ�.
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// ���� �湮���� �ʾҴٸ�
		if (d[y] == 0) {
			parent = min(parent, dfs(y));
		}
		// dfs�� �湮�Ǿ�����, ó���� ���� ���� ���
		else if (!finished[y]) {
			parent = min(parent, d[y]);
		}
	}
	// ���� scc�� �θ� �ڱ� �ڽ��� ���
	if (d[x] == parent) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			// ó�� �Ϸ� ǥ�ø� ���ݴϴ�.
			finished[t] = true;
			// ���� node�� group id�� �������ݴϴ�.
			group[t] = SCC.size() + 1;
			// stack���� ������ ���� ������ �ݺ��մϴ�.
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		fill(group, group + MAX, 0);
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		// ��� node�� ���ؼ� ��� �� ������ dfs�� �ǽ��ϵ��� �Ѵ�.
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				// ����� node �� �ٸ� scc�� ���� node�� �����ϴ� ��� inDegree�� true�� ��ȯ���ش�.
				if (group[i] != group[y]) {
					inDegree[group[y]] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= SCC.size(); i++) {
			if (!inDegree[i]) cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}

/*
�� ������ scc������ �Ϲ��������� ������ �Ǿ��ְ�, �׷��ٸ�
topology sort�� �����Ͽ� Ǯ �� �ִٴ� ������ �ľ��ϰ� �־��
Ǯ �� �ִ� �����Դϴ�.

���̳븦 ����Ʈ���� ������ ���ϱ� ���ؼ��� ���������� 0��
scc�� ������ ���ϸ� �� �� �����ϴ�.

�ܼ��� ���� ������ �����Ͽ� scc�� �Ѿ����� ������ ���ϴ� �ͱ�����
�ʿ����, �׳� DAG graph�� �������� �� ���������� 0�� node�� ����
���ص� �� �� ����.
*/