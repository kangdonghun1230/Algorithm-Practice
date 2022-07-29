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
		// 해당 노드를 방문처리한다.
		visited[nx][ny] = true;

		if (arr[nx][ny] > h) {
			pq.push({ arr[nx][ny], {nx, ny} });
		}
		else {
			res += (h - arr[nx][ny]);
			// 다음 위치에 대해서 recursively call DFS
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
사이즈 보니까 둘러쌀 수 있는 최대 높이를 계산해야 하는 문제같다.

그래프를 돌면서 이 최댓값을 찾아야 한다.

dp에 저장할 값 -> 내 근처의 테두리 중에서 가장 낮은 것 (내거 포함)
*/