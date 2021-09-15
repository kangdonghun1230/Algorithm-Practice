#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100001

using namespace std;

bool inDegree[MAX];
int d[MAX];
bool finished[MAX];
int id, n, m;

vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;
int group[MAX];
vector<int> result;

int dfs(int x) {
	// dfs방문 표시로 고유의 id부여
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		// y는 인접한 node
		int y = a[x][i];
		if (d[y] == 0) {
			parent = min(parent, dfs(y));
		}
		else if (!finished[y]) {
			parent = min(parent, d[y]);
		}
	}

	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			scc.push_back(t);
			group[t] = SCC.size() + 1;
			// stack에서 x를 뽑을때까지 반복
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
		result.clear();

		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			a[x + 1].push_back(y + 1);
		}
		// 모든 node에 대해서 적어도 한 번씩은 dfs를 실시하도록 한다.
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				if (group[i] != group[y]) {
					// 인접한 노드인 경우 진입차수 존재여부 표현한다.
					inDegree[group[y]] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < SCC.size(); i++) {
			if (!inDegree[i + 1]) {
				cnt++;
				for (int j = 0; j < SCC[i].size(); j++) {
					result.push_back(SCC[i][j] - 1);
				}
			}			
		}
		sort(result.begin(), result.end());
		// 출발지가 여러군데이거나 없는 경우 confused
		if (cnt != 1) {
			printf("Confused\n\n");
		}
		else {
			for (int i = 0; i < result.size(); i++) {
				printf("%d\n", result[i]);
			}
			printf("\n");
		}

	}
	return 0;
}