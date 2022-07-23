/*
	Date: 2022/07/20
	Brief:
	Dijkstra
	Reference:
*/
#include <iostream>
#include <string>
#include <queue>

#define MAX 51
#define INF 2501
using namespace std;

string houseInfo[MAX];
int res = INF;

int n;
// 0(상), 1(하), 2(좌), 3(우)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 같은 거리여도 같은 방향이 아닌 경우 존재할 수 있다. (중복 처리를 막기 위해서 필요하다고 함)
// 사실 그냥 이미 현재의 최솟값을 넘어서면 컷한다는 기준으로 구현해도 좋지 않을까 싶다.
bool visited[MAX][MAX][2501][4] = {false,};

vector<pair<int, int>> doorSite;

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void BFS(int x, int y) {
	// pair<pair<거울 수, 방향>, pair<x, y>>
	queue<pair<pair<int, int>, pair<int, int>>> q;

	// 첫 문의 4방향을 queue에 넣어준다.
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		int next_g = 0;
		int next_d = i;

		if (!inRange(next_x, next_y))
			continue;
		// 다음 칸이 벽인 경우 스킵
		if (houseInfo[next_x][next_y] == '*')
			continue;
		visited[next_x][next_y][next_g][next_d] = true;
		q.push({ {next_g, next_d}, {next_x, next_y} });
	}

	while (!q.empty()) {
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;

		int cur_g = q.front().first.first;
		int cur_d = q.front().first.second;
		q.pop();

		if (cur_g > res)
			continue;

		//cout << cur_x << " " << cur_y << " " << cur_g << " " << cur_d << endl;
		// 현재 칸이 문인 경우
		if (houseInfo[cur_x][cur_y] == '#' && cur_x == doorSite[1].first && cur_y == doorSite[1].second) {
			// 문에 도착한 경우 갱신 가능한지 판단한다.
			res = (res > cur_g) ? cur_g : res;
			continue;
		}
		else if (houseInfo[cur_x][cur_y] == '.') {
			// 빈 공간인 경우 이전 방향 그대로 진행한다.
			int next_x = cur_x + dx[cur_d];
			int next_y = cur_y + dy[cur_d];

			int next_g = cur_g;
			int next_d = cur_d;

			if (!inRange(next_x, next_y))
				continue;
			// 다음 칸이 벽인 경우 스킵 or 이미 방문한 경우 스킵
			if (houseInfo[next_x][next_y] == '*' || visited[next_x][next_y][next_g][next_d])
				continue;
			visited[next_x][next_y][next_g][next_d] = true;
			q.push({ {next_g, next_d}, {next_x, next_y} });
		}
		else {
			// 거울인 경우 세 개의 방향으로 틀어진다. (현재 진행 방향에 수직 or 그대로 간다.)
			for (int i = 0; i < 4; i++) {
				if (cur_d == 0 && i == 1)
					continue;
				if (cur_d == 1 && i == 0)
					continue;
				if (cur_d == 2 && i == 3)
					continue;
				if (cur_d == 3 && i == 2)
					continue;
				

				int next_x = cur_x + dx[i];
				int next_y = cur_y + dy[i];

				int next_g = cur_g;
				int next_d = i;

				//cout << "거울: " << next_x << " " << next_y << " " << next_g << " " << next_d << endl;

				if (!inRange(next_x, next_y))
					continue;
				// 다음 칸이 벽인 경우 스킵
				if (houseInfo[next_x][next_y] == '*')
					continue;

				// 진행 방향이 바뀌는 경우 거울 수를 추가한다. (거울을 설치하는 경우)
				if (next_d != cur_d)
					next_g++;

				// 이미 방문한 경우 스킵한다.
				if (visited[next_x][next_y][next_g][next_d])
					continue;

				visited[next_x][next_y][next_g][next_d] = true;
				//cout << "거울" << next_x << " " << next_y << " " << next_g << " " << next_d << endl;
				q.push({ {next_g, next_d}, {next_x, next_y} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> houseInfo[i];
	}
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (houseInfo[i][j] == '#') {
				doorSite.push_back({ i, j });
			}
		}
	}
	BFS(doorSite[0].first, doorSite[0].second);

	cout << res << "\n";

	return 0;
}

/*
idea

거울을 설치할 수 있는 위치에서 택할 수 있는 옵션
1. 그대로 간다
2. 거울을 설치하고 + 진행 방향을 바꾼다 (2가지)

거울이 없는 빈 공간
1. 그대로 간다

벽
1. 못간다

문
1. 4개의 방향으로 진행 가능

따라서 진행 방향을 큐에 넣는 방식의 다익스트라 알고리즘을 활용해야 될 것으로 보인다.

*유의할 점
어느 문에서 출발할 지가 문제인데, 이것은 가장 먼저 detect 되는 문을 출발점으로 삼는 것으로 정하자.

*/