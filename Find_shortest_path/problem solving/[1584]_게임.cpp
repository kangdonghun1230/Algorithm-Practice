/*
	Date: 2022/07/18
	Brief:
	BFS
	Reference:
*/
#include <iostream>
#include <queue>

#define MAX 501

using namespace std;

int map[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];

bool inRange(int x, int y) {
	return (0 <= x && x < MAX && 0 <= y && y < MAX);
}

void BFS(int x, int y) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push({ 0, {x, y} });

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;

	// 굳이 아래의 과정을 수행할 필요가 없다.
	if (map[500][500] == -1)
		return;


	while (!q.empty()) {
		int curX = q.top().second.first;
		int curY = q.top().second.second;
		int life = q.top().first;
		q.pop();


		if (curX == 500 && curY == 500)
			break;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			int nextLife = life + map[nextX][nextY];

			if (!inRange(nextX, nextY))
				continue;

			if (visited[nextX][nextY])
				continue;

			// 죽음의 구역은 pass
			if (map[nextX][nextY] == -1)
				continue;

			visited[nextX][nextY] = true;
			q.push({ nextLife, {nextX, nextY} });
			dp[nextX][nextY] = nextLife;
		}
	}
}

int main() {
	int dangerPoints;
	int deathPoints;
	int i, j, k;

	cin.tie(NULL);
	cin >> dangerPoints;

	for (i = 0; i < dangerPoints; i++) {
		int staX, staY;
		int endX, endY;
		int tmp;
		cin >> staX >> staY >> endX >> endY;

		if (staX > endX) {
			tmp = staX;
			staX = endX;
			endX = tmp;
		}

		if (staY > endY) {
			tmp = staY;
			staY = endY;
			endY = tmp;
		}

		// 위험한 구역은 생명이 1씩 소모된다.
		for (j = staX; j <= endX; j++) {
			for (k = staY; k <= endY; k++) {
				map[j][k] = 1;
			}
		}
	}

	cin >> deathPoints;

	for (i = 0; i < deathPoints; i++) {
		int staX, staY;
		int endX, endY;
		int tmp;

		cin >> staX >> staY >> endX >> endY;

		if (staX > endX) {
			tmp = staX;
			staX = endX;
			endX = tmp;
		}

		if (staY > endY) {
			tmp = staY;
			staY = endY;
			endY = tmp;
		}

		// 죽음의 구역은 접근 불가
		for (j = staX; j <= endX; j++) {
			for (k = staY; k <= endY; k++) {
				map[j][k] = -1;
			}
		}
	}

	BFS(0, 0);
	visited[0][0] = true;
	if (dp[500][500] == -1)
		cout << "-1\n";
	else
		cout << dp[500][500] << "\n";

	return 0;
}

/*
priority queue default로 내림 차순으로 정렬되는걸 잊었다.
*/