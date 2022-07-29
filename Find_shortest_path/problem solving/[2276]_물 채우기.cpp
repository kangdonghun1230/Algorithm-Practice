/*
	Date: 2022/07/25
	Brief:
	Dijkstra
	Reference:
*/
#include <iostream>
#include <queue>
#include <vector>
#define MAX 301

using namespace std;

int n, m;
int arr[MAX][MAX];
int res;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool visited[MAX][MAX];

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

void DFS(int x, int y, int h) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (!inRange(nx, ny) || visited[nx][ny])
			continue;
		// �ش� ��带 �湮ó���Ѵ�.
		visited[nx][ny] = true;

		if (arr[nx][ny] > h) {
			pq.push({ arr[nx][ny], {nx, ny} });
		}
		else {
			res += (h - arr[nx][ny]);
			// ���� ��ġ�� ���ؼ� recursively call DFS
			DFS(nx, ny, h);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				pq.push({ arr[i][j], {i, j} });
				visited[i][j] = true;
			}
		}
	}

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int h = pq.top().first;
		pq.pop();

		DFS(x, y, h);
	}

	cout << res << "\n";

	return 0;
}

/*
������ ���ϱ� �ѷ��� �� �ִ� �ִ� ���̸� ����ؾ� �ϴ� ��������.

�׷����� ���鼭 �� �ִ��� ã�ƾ� �Ѵ�.

dp�� ������ �� -> �� ��ó�� �׵θ� �߿��� ���� ���� �� (���� ����)
*/