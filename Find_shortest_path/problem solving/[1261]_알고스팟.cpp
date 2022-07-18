/*
	Date: 2022/07/18
	Brief:
	Dijkstra
	Reference:
*/
#include <iostream>
#include <queue>
#define MAX 101
#define DIS_MAX 201

using namespace std;

int n, m;
string map[MAX];
int dp[MAX][MAX];

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

class Pos {
public:
	int x;
	int y;

	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void dijkstra(int x, int y) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {x, y} });

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	// initialize dp array with 201
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = DIS_MAX;
		}
	}

	dp[x][y] = 0;

	while (!pq.empty()) {
		Pos cur = { pq.top().second.first, pq.top().second.second };
		int dis = pq.top().first;

		// pop from the priority queue
		pq.pop();

		for (int i = 0; i < 4; i++) {
			Pos next = Pos(cur.x + dx[i], cur.y + dy[i]);
			int next_dis = dis;

			if (!inRange(next.x, next.y))
				continue;

			// 다음 경로가 벽인 경우 count + 1
			if (map[next.x][next.y] == '1') {
				next_dis += 1;
			}

			if (dp[next.x][next.y] > next_dis) {
				dp[next.x][next.y] = next_dis;
				pq.push({ next_dis, {next.x, next.y} });
			}
		}
	}

	return; 
}

int main() {
	int i, j;

	cin.tie(NULL);
	cin >> m >> n;

	for (i = 0; i < n; i++) {
		cin >> map[i];
	}

	dijkstra(0, 0);

	cout << dp[n - 1][m - 1] << endl;

	return 0;
}

// 다익스트라 기본
//
// 1. 출발 노드를 큐에 넣는다.
// 2. while문을 큐가 빌때까지 반복
// 3. 큐에서 front node를 pop한 후 해당 노드의 인접 노드를 확인 (queue에 거리가 짧은 순으로 담겨야한다.)
// 4. 인접 노드를 거쳐서 갈 수 있는 목적지 중 최단 경로 갱신이 가능한 경우
// 5. 최단 경로 갱신한 후 큐에 push
// 6. 2 ~ 4 반복