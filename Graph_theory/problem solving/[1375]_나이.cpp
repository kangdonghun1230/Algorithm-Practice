/*
	Date: 2022/07/28
	Brief:
	Topology sort
	Reference:
*/
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000001

using namespace std;

vector<int> v[MAX];
int inDegree[MAX];
// order, count
pair<int, int> order[MAX];

int k, m, p;

void topologySort() {
	queue<int> q;

	for (int i = 1; i <= m; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			order[i] = {1, 1};
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];

			// ���� ������ ������ ������ counting
			if (order[y] == order[x]) {
				order[y].second++;
			}
			// ������ �ٸ��ٸ� �� ū ������ counting, ������ 1�� ����
			else if (order[y].first < order[x].first) {
				order[y].first = order[x].first;
				order[y].second = 1;
			}

			if (--inDegree[y] == 0) {
				// 2�� �Ѿ�� ���� + 1
				if (order[y].second >= 2) {
					order[y].first++;
					order[y].second = 1;
				}
				q.push(y);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> k >> m >> p;

		for (int i = 1; i <= m; i++) {
			v[i].clear();
			inDegree[i] = 0;
			order[i] = {0, 0};
		}

		for (int i = 0; i < p; i++) {
			int a, b;
			cin >> a >> b;

			v[a].push_back(b);
			inDegree[b]++;
		}
		topologySort();

		cout << k << " " << order[m].first << "\n";
	}

	return 0;
}