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

	// ���� ������ 0�� �� ���� ����� queue�� �ִ´�.
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
				// x�� ���� �б⿡ y�� ������ �� �ִ� �����̱� �����̴�.
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
		// b�� �������� ����
		inDegree[b]++;
	}

	topologySort();

	for (int i = 1; i <= n; i++) {
		cout << semester[i] << " ";
	}

	return 0;
}