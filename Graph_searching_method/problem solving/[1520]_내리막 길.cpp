#include <iostream>

#define MAX 501
#define endl '\n'

using namespace std;

int m, n;

int world[MAX][MAX];
//현재 지점에서 목적지로 가는 경우의 수를 표현한다.
int d[MAX][MAX];

bool inRange(int x, int y) {
	return (0 <= x && x < m && 0 <= y && y < n);
}

void init() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = -1;
		}
	}
}
int dfs(int x, int y) {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	//목적지에 도달한 경우 1을 반환한다. (직전 칸에 들어갈 값이므로)
	if (x == m - 1 && y == n - 1)
		return 1;
	
	//이미 방문한 칸의 경우 현재 칸에서 목적지로 가는 경우의 수를 반환한다.
	if (d[x][y] != -1)
		return d[x][y];

	d[x][y] = 0;
	//4가지 방향으로 살펴본다.
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (world[nx][ny] >= world[x][y] || !inRange(nx, ny))
			continue;

		//이후 경로에서 목적지로 가는 경우의 수를 모두 더하면 된다.
		d[x][y] += dfs(nx, ny);
	}

	return d[x][y];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> world[i][j];
		}
	}

	init();
	cout << dfs(0, 0) << endl;

	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}