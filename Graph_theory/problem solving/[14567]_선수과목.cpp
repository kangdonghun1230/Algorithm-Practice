/*
	Date: 2022/07/25
	Brief:
	Topology sort
	Reference:
*/
#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;

int n, m;

vector<int> v[MAX];
int inDegree[MAX];
int semester[MAX];

void topologySort() {
	queue<int> q;

	// 진입 차수가 0인 할 일의 목록을 queue에 넣는다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			semester[i] = 1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];

			if (--inDegree[y] == 0) {
				q.push(y);
				// x의 다음 학기에 y를 수강할 수 있는 구조이기 때문이다.
				semester[y] = semester[x] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		// b의 진입차수 증가
		inDegree[b]++;
	}

	topologySort();

	for (int i = 1; i <= n; i++) {
		cout << semester[i] << " ";
	}

	return 0;
}