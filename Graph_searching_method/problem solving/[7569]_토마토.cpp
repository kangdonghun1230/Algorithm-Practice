/*
	Date: 2022/05/09
	Brief:
	BFS
	Reference:
*/
#include <iostream>
#include <queue>
#include <tuple>

#define MAX 101

using namespace std;

int box[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int n, m, h;

bool inRange(int x, int y, int z) {
	return (0 <= x && x < n && 0 <= y && y < m && 0 <= z && z < h);
}

void BFS() {
	int i, j, k;
	queue<tuple<int, int, int>> q;
	
	for (i = 0; i < h; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				if (box[i][j][k] == 1) {
					q.push(make_tuple(j, k, i));
					visited[i][j][k] = 1;
				}
			}
		}
	}

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			int next_z = z + dz[i];

			if (!inRange(next_x, next_y, next_z))
				continue;

			if (visited[next_z][next_x][next_y] == 0 && box[next_z][next_x][next_y] == 0) {
				box[next_z][next_x][next_y] = 1;
				visited[next_z][next_x][next_y] = visited[z][x][y] + 1;
				q.push(make_tuple(next_x, next_y, next_z));
			}
		}
	}
	return;
}

int main() {
	int i, j, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;

	for (i = 0; i < h; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				cin >> box[i][j][k];
			}
		}
	}

	// call BFS function
	BFS();

	bool res = true;
	int max = 0;
	// 모든 토마토가 익었는지 확인
	for (i = 0; i < h; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				if (!visited[i][j][k] && box[i][j][k] == 0) {
					res = false;
				}
				max = (max > visited[i][j][k]) ? max : visited[i][j][k];
			}
		}
	}

	if (res) {
		cout << max - 1 << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}