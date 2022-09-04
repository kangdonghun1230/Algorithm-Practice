#include <iostream>
#include <queue>
#define MAX 301 

using namespace std;

int t, n;
int cur_x, cur_y;
int des_x, des_y;

bool visited[MAX][MAX] = { false, };

void input() {
	cin >> n;
	cin >> cur_x >> cur_y;
	cin >> des_x >> des_y;

	return;
}

void initialize() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
	return;
}

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int BFS() {
	queue<pair<pair<int, int>, int>> q;

	q.push({ { cur_x, cur_y }, 0 });
	visited[cur_x][cur_y] = true;

	int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
	int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };


	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next_cnt = cnt + 1;

			if (!inRange(nx, ny) || visited[nx][ny])
				continue;

			if (nx == des_x && ny == des_y) {
				return next_cnt;
			}
			else {
				visited[nx][ny] = true;
				q.push({ {nx, ny}, next_cnt });
			}
		}
	}

	return 0;
}

int main() {
	int t;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		input();
		initialize();

		cout << BFS() << "\n";
	}

	return 0;
}