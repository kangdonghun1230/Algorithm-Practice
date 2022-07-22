/*
	Date: 2022/07/20
	Brief:
	Dijkstra
	Reference:
*/
#include <iostream>
#include <queue>
#define MAX 2223
#define INF 10000000

using namespace std;

int arr[MAX][MAX];
int minMoney[MAX][MAX];
int n;

bool inRange(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= n);
}

void initialization() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			minMoney[i][j] = INF;
		}
	}
}

void dijkstra(int x, int y) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {x, y} });

	int dx[] = { 0, 1 };
	int dy[] = { 1, 0 };

	minMoney[x][y] = 0;

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int money = pq.top().first;
		pq.pop();

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next_money = money;
			if (!inRange(nx, ny))
				continue;
			// 현재 기준 누적 금액 계산
			if (arr[nx][ny] >= arr[x][y]) {
				next_money += (arr[nx][ny] - arr[x][y] + 1);
			}
			// 갱신 안되는 경우 skip
			if (next_money >= minMoney[nx][ny])
				continue;

			minMoney[nx][ny] = next_money;
			pq.push({ next_money, {nx, ny} });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	initialization();

	dijkstra(1, 1);

	cout << minMoney[n][n] << "\n";

	return 0;
}