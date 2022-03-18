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
// 각 정점들이 어떤 그룹에 속하는지를 알기 위해서
int group[MAX];
bool inDegree[MAX];

int dfs(int x) {
	// 고유한 id를 할당하고 stack에 넣어줍니다.
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// 아직 방문되지 않았다면
		if (d[y] == 0) {
			parent = min(parent, dfs(y));
		}
		// dfs로 방문되었지만, 처리가 되지 않은 경우
		else if (!finished[y]) {
			parent = min(parent, d[y]);
		}
	}
	// 현재 scc의 부모가 자기 자신인 경우
	if (d[x] == parent) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			// 처리 완료 표시를 해줍니다.
			finished[t] = true;
			// 현재 node의 group id를 설정해줍니다.
			group[t] = SCC.size() + 1;
			// stack에서 본인을 뽑을 때까지 반복합니다.
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
		// 모든 node에 대해서 적어도 한 번씩은 dfs를 실시하도록 한다.
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				// 연결된 node 중 다른 scc에 속한 node가 존재하는 경우 inDegree를 true로 전환해준다.
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
이 문제는 scc끼리는 일방향적으로 연결이 되어있고, 그렇다면
topology sort를 적용하여 풀 수 있다는 개념을 파악하고 있어야
풀 수 있는 문제입니다.

도미노를 쓰러트리는 개수를 구하기 위해서는 진입차수가 0인
scc의 개수를 구하면 될 것 같습니다.

단순히 위상 정렬을 수행하여 scc가 넘어지는 순서를 구하는 것까지도
필요없고, 그냥 DAG graph를 구성했을 때 진입차수가 0인 node의 수만
구해도 될 것 같다.
*/