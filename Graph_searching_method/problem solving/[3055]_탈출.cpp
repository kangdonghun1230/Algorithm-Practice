#include <iostream>
#include <queue>
#include <string>

#define MAX 51
#define MAX_VAL 2501

using namespace std;

int r, c;
int d, s;

string map[MAX];
int dp[MAX][MAX];

queue<pair<int, int>> q;
queue<pair<int, int>> waterQueue;

void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dp[i][j] = MAX_VAL;
		}
	}
}

bool inRange(int x, int y) {
	return (0 <= x && x < r && 0 <= y && y < c);
}

void findMinPath() {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	
	while (!q.empty()) {
		//현재 물이 범람한 칸만 탐색하기 위함이다.
		int waterQueueSize = waterQueue.size();
		for (int i = 0; i < waterQueueSize; i++) {

			int currentWaterX = waterQueue.front().first;
			int currentWaterY = waterQueue.front().second;
			waterQueue.pop();

			for (int j = 0; j < 4; j++) {
				int nextWaterX = currentWaterX + dx[j];
				int nextWaterY = currentWaterY + dy[j];

				//범위 밖인지 확인한다.
				if (!inRange(nextWaterX, nextWaterY))
					continue;

				if (map[nextWaterX][nextWaterY] == '.') {
					//해당 칸은 물이 범람함
					map[nextWaterX][nextWaterY] = '*';
					waterQueue.push({ nextWaterX, nextWaterY });
				}
			}
		}
		int queueSize = q.size();

		for (int i = 0; i < queueSize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			int dis = dp[x][y];
			q.pop();

			//도착지점이면 종료한다 (어차피 BFS)
			if (map[x][y] == 'D') {
				cout << dp[x][y];
				return;
			}

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				int nextDis = dis + 1;

				if (!inRange(nx, ny) || (nextDis >= dp[nx][ny]))
					continue;
				//물이 범람한 지역이거나 출발 지점인 경우는 건너띈다. (돌 포함)
				if (map[nx][ny] == '*' || map[nx][ny] == 'S' || map[nx][ny] == 'X')
					continue;

				//최단 시간 갱신하고, queue에 넣는다.
				dp[nx][ny] = nextDis;
				q.push({ nx, ny });
			}
		}
	}

	//결국 목적지에 도달하지 못한 경우에 해당한다.
	cout << "KAKTUS";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int desX, desY;

	cin >> r >> c;

	init();

	for (int i = 0; i < r; i++) {
		string row;
		cin >> row;
		map[i] = row;

		for (int j = 0; j < c; j++) {
			if (row[j] == '*') {
				waterQueue.push({ i, j });
			}
			else if (row[j] == 'S') {
				q.push({ i, j });
				dp[i][j] = 0;
			}
		}
	}

	findMinPath();

	return 0;
}