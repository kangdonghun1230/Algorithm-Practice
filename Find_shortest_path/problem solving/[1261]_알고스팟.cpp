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

			// ���� ��ΰ� ���� ��� count + 1
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

// ���ͽ�Ʈ�� �⺻
//
// 1. ��� ��带 ť�� �ִ´�.
// 2. while���� ť�� �������� �ݺ�
// 3. ť���� front node�� pop�� �� �ش� ����� ���� ��带 Ȯ�� (queue�� �Ÿ��� ª�� ������ ��ܾ��Ѵ�.)
// 4. ���� ��带 ���ļ� �� �� �ִ� ������ �� �ִ� ��� ������ ������ ���
// 5. �ִ� ��� ������ �� ť�� push
// 6. 2 ~ 4 �ݺ�