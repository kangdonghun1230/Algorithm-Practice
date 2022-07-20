/*
	Date: 2022/07/20
	Brief:
	Dijkstra algorithm + 조금의 구현
	Reference:
	https://github.com/devxb/JJUNalgo/blob/master/2158%20%EC%82%B0%EC%95%85%EC%9E%90%EC%A0%84%EA%B1%B0/main.cpp
	https://pmoncode.tistory.com/20
*/
#include <iostream>
#include <queue>
#include <cmath>

#define MAX 101

typedef long double ld;

using namespace std;
// -25 ~ 25 범위의 고도가 가능하기 때문에 2^50 범위까지 커버할 수 있어야 한다.
const ld INF = 1000000000000001;
int v, r, c;
int mountain[MAX][MAX]; // 각 칸에서의 고도 정보를 표현한다.
pair<ld, ld> dp[MAX][MAX]; // 각 칸까지 최소 시간을 저장한다.

bool inRange(int x, int y) {
	return (1 <= x && x <= r && 1 <= y && y <= c);
}

void dijkstra(int r, int c, ld v) {
	// priority queue 선언 -> heap으로 이용하기 위해서 (내림차순으로 변경)
	priority_queue<pair<pair<ld, ld>, pair<int, int>>, vector<pair<pair<ld, ld>, pair<int, int>>>, greater<pair<pair<ld, ld>, pair<int, int>>>> pq;

	// 거리, 속도가 가장 높은 것부터 queue에서 꺼내겠음
	pq.push({ { 0, v}, { r, c } });

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	while (!pq.empty()) {
		// 다음 칸으로 갔을 때 이동 거리는 현재 속도와 고도로 결정된다.
		ld cur_d = pq.top().first.first; // 현재 거리
		ld cur_v = pq.top().first.second;// 현재 속도
		int cur_r = pq.top().second.first; // 현재 r 좌표
		int cur_c = pq.top().second.second;// 현재 c 좌표
		pq.pop();

		// 갱신할 필요 없는 경우는 스킵한다.
		if (dp[cur_r][cur_c].first < cur_d)
			continue;
		if (dp[cur_r][cur_c].first == cur_d && dp[cur_r][cur_c].second > cur_v)
			continue;

		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dx[i];
			int next_c = cur_c + dy[i];

			// 범위 밖인 경우 건너띈다.
			if (!inRange(next_r, next_c))
				continue;
			// 다음 위치에서의 거리와 속도를 계산한다.
			ld next_v = cur_v * pow(2, mountain[cur_r][cur_c] - mountain[next_r][next_c]);
			ld next_d = cur_d + (1 / cur_v);

			if (dp[next_r][next_c].first > next_d) {
				// 다음 위치에서의 거리와 속도 갱신
				dp[next_r][next_c].first = next_d;
				dp[next_r][next_c].second = next_v;
				pq.push({ {next_d, next_v}, {next_r, next_c} });
				//cout << next_r << " " << next_c << " " << dp[next_r][next_c] << endl;
			}
			// 거리는 같지만, 속도가 더 빠른 상태로 이동하는 경우
			else if (dp[next_r][next_c].first == next_d && dp[next_r][next_c].second < next_v) {
				// 다음 위치에서의 속도 갱신
				dp[next_r][next_c].second = next_v;
				pq.push({ {next_d, next_v}, {next_r, next_c} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mountain[i][j];
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			dp[i][j].first = INF;
			dp[i][j].second = 0;
		}
	}
	dp[1][1] = { 0, v };
	dijkstra(1, 1, v);

	// cout << fixed는 소수점을 고정시켜 표현하겠음을 의미한다.
	cout << fixed;
	cout.precision(2);
	cout << dp[r][c].first;

	return 0;
}