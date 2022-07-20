/*
	Date: 2022/07/20
	Brief:
	Dijkstra algorithm + ������ ����
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
// -25 ~ 25 ������ ���� �����ϱ� ������ 2^50 �������� Ŀ���� �� �־�� �Ѵ�.
const ld INF = 1000000000000001;
int v, r, c;
int mountain[MAX][MAX]; // �� ĭ������ �� ������ ǥ���Ѵ�.
pair<ld, ld> dp[MAX][MAX]; // �� ĭ���� �ּ� �ð��� �����Ѵ�.

bool inRange(int x, int y) {
	return (1 <= x && x <= r && 1 <= y && y <= c);
}

void dijkstra(int r, int c, ld v) {
	// priority queue ���� -> heap���� �̿��ϱ� ���ؼ� (������������ ����)
	priority_queue<pair<pair<ld, ld>, pair<int, int>>, vector<pair<pair<ld, ld>, pair<int, int>>>, greater<pair<pair<ld, ld>, pair<int, int>>>> pq;

	// �Ÿ�, �ӵ��� ���� ���� �ͺ��� queue���� ��������
	pq.push({ { 0, v}, { r, c } });

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	while (!pq.empty()) {
		// ���� ĭ���� ���� �� �̵� �Ÿ��� ���� �ӵ��� ���� �����ȴ�.
		ld cur_d = pq.top().first.first; // ���� �Ÿ�
		ld cur_v = pq.top().first.second;// ���� �ӵ�
		int cur_r = pq.top().second.first; // ���� r ��ǥ
		int cur_c = pq.top().second.second;// ���� c ��ǥ
		pq.pop();

		// ������ �ʿ� ���� ���� ��ŵ�Ѵ�.
		if (dp[cur_r][cur_c].first < cur_d)
			continue;
		if (dp[cur_r][cur_c].first == cur_d && dp[cur_r][cur_c].second > cur_v)
			continue;

		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dx[i];
			int next_c = cur_c + dy[i];

			// ���� ���� ��� �ǳʶ��.
			if (!inRange(next_r, next_c))
				continue;
			// ���� ��ġ������ �Ÿ��� �ӵ��� ����Ѵ�.
			ld next_v = cur_v * pow(2, mountain[cur_r][cur_c] - mountain[next_r][next_c]);
			ld next_d = cur_d + (1 / cur_v);

			if (dp[next_r][next_c].first > next_d) {
				// ���� ��ġ������ �Ÿ��� �ӵ� ����
				dp[next_r][next_c].first = next_d;
				dp[next_r][next_c].second = next_v;
				pq.push({ {next_d, next_v}, {next_r, next_c} });
				//cout << next_r << " " << next_c << " " << dp[next_r][next_c] << endl;
			}
			// �Ÿ��� ������, �ӵ��� �� ���� ���·� �̵��ϴ� ���
			else if (dp[next_r][next_c].first == next_d && dp[next_r][next_c].second < next_v) {
				// ���� ��ġ������ �ӵ� ����
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

	// cout << fixed�� �Ҽ����� �������� ǥ���ϰ����� �ǹ��Ѵ�.
	cout << fixed;
	cout.precision(2);
	cout << dp[r][c].first;

	return 0;
}