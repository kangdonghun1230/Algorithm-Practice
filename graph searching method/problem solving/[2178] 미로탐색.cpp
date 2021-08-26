#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

char maze[101][101];
int n, m;

int x_range[] = { 1, 0, -1, 0 };
int y_range[] = { 0, 1, 0, -1 };

int cnt[101][101];

bool visited[101][101];

// x, y가 list 내의 좌표인지를 확인한다.
bool isRange(int x, int y) {
	return (x >= 0 && x < m) && (y >= 0 && y < n);
}

void BFS(int x, int y) {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(1, make_pair(x, y)));
	cnt[y][x] = 1;

	while (!q.empty()) {
		int dis = q.front().first;
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + x_range[i];
			int next_y = cur_y + y_range[i];
			int next_dis = dis + 1;
			if (isRange(next_x, next_y) && (maze[next_y][next_x] == '1')) {
				if (!visited[next_y][next_x]) {
					visited[next_y][next_x] = true;
					q.push(make_pair(next_dis, make_pair(next_x, next_y)));
					cnt[next_y][next_x] = next_dis;
				}
			}
		}

	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	// get maze information
	for (int i = 0; i < n; i++) {
		scanf("%s", &maze[i]);
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", maze[i][j]);
		}printf("\n");
	}*/

	BFS(0, 0);

	printf("%d\n", cnt[n-1][m-1]);

	return 0;
}