/*
	Date: 2022/08/20
	Brief:
	BFS
	Reference:
*/
#include <iostream>
#include <queue>
#define MAX 51

using namespace std;

int w, h;
int arr[MAX][MAX];
bool visited[MAX][MAX];

bool inRange(int x, int y) {
	return (0 <= x && x < h && 0 <= y && y < w);
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;

	// 상, 하, 좌, 우, 4 방향의 대각선
	int dx[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
	int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };

	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];

			if (visited[nextX][nextY] || arr[nextX][nextY] == 0 || !inRange(nextX, nextY))
				continue;

			visited[nextX][nextY] = true;
			q.push({ nextX, nextY });
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
			}
		}

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					cnt++;
					BFS(i, j);
				}
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}