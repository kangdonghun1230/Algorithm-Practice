#include <iostream>
#include <queue>
#define MAX 17

using namespace std;

int n;
int home[MAX][MAX];

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

bool checkDir(int cur_dir, int next_dir) {
	if (cur_dir == 0 && next_dir == 2)
		return false;
	else if (cur_dir == 2 && next_dir == 0)
		return false;
	else
		return true;
}

int BFS() {
	// tail의 좌표, 방향
	queue<pair<pair<int, int>, int>> q;
	int res = 0;

	// (우, 우하, 하) 세 가지의 방향으로 이동할 수 있다.
	int dx[] = { 0, 1, 1 };
	int dy[] = { 1, 1, 0 };

	// 파이프의 초기 위치는 (0, 0), (0, 1) 이다.
	q.push({ {0, 0}, 0 });

	while (!q.empty()) {
		int tail_x = q.front().first.first, tail_y = q.front().first.second;
		int dir = q.front().second;
		int head_x = tail_x + dx[dir], head_y = tail_y + dy[dir];

		q.pop();

		if (head_x == n - 1 && head_y == n - 1) {
			res++;
			continue;
		}

		for (int i = 0; i < 3; i++) {
			if (!checkDir(dir, i))
				continue;

			int next_head_x = head_x + dx[i];
			int next_head_y = head_y + dy[i];

			// 집을 벗어나는 경우는 스킵한다.
			if (!inRange(next_head_x, next_head_y))
				continue;

			// 벽이 있는 경우도 못간다.
			bool isThereWall = false;
			for (int i = head_x; i <= next_head_x; i++) {
				for (int j = head_y; j <= next_head_y; j++) {
					if (home[i][j] == 1)
						isThereWall = true;
				}
			}
			if (isThereWall) continue;

			q.push({ {head_x, head_y}, i });
		}

	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> home[i][j];
		}
	}

	cout << BFS();

	return 0;
}