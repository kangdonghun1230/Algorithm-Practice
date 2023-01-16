#include <iostream>
#include <queue>

#define MAX_N 51
#define MAX 2501

using namespace std;

int n;
string m[MAX_N];
int d[MAX_N][MAX_N]; //각 지점에서의 최소 방 색상 전환 수를 저장하는 2차원 배열

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = MAX;
		}
	}
}

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void BFS() {
	init(); //최소 정보 배열을 초기화하고 시작한다.
	queue<pair<int, pair<int, int>>> q;
	//출발점을 queue에 넣는다.
	q.push({ 0, {0, 0} });
	d[0][0] = 0;

	while (!q.empty()) {
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;
		int cur_black_num = q.front().first;

		q.pop();

		//인접한 방을 방문하면서 최소 검은색 전환 결과를 계산해본다.
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			int next_black_num = cur_black_num;

			if (!inRange(next_x, next_y))
				continue;

			if (m[next_x][next_y] == '0') {
				next_black_num++;
			}

			if (d[next_x][next_y] > next_black_num) {
				d[next_x][next_y] = next_black_num;
				q.push({ next_black_num, {next_x, next_y} });
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	BFS();

	cout << d[n - 1][n - 1];

	return 0;
}
//탐색을 진행하면서, 고려해야할 cost는 현재 몇 개의 검은 방을 지나왔는지이다.
//검은 방으로 변경하면서 진행하는 것이 아니라 현재 경로에서 몇 개의 검은 방을 지났는지가 중요
