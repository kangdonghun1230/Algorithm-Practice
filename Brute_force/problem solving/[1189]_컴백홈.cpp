/*
	Date: 2022/07/08
	Brief:
	Backtracking, Bruteforce
	Reference:
*/
#include <iostream>
#include <string>

using namespace std;

int r, c; // row, column
int k;

int res;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

string map[5];

bool visited[5][5];

bool inRange(int x, int y) {
	return (0 <= x && x < r && 0 <= y && y < c);
}

void DFS(int cnt, int x, int y) {
	// k번 이동해서 도착에 성공한 경우 (우측 상단이 도착)
	if (cnt == k && x == 0 && y == (c - 1)) {
		res++;
		return;
	}
	// k번 이동했는데 도착에 실패한 경우
	else if (cnt == k)
		return;

	for (int i = 0; i < 4; i++) {
		int n_x = x + dx[i];
		int n_y = y + dy[i];

		// check next point's position is in the map
		if (!inRange(n_x, n_y) || visited[n_x][n_y] || (map[n_x][n_y] == 'T'))
			continue;

		visited[n_x][n_y] = true;
		DFS(cnt + 1, n_x, n_y);
		visited[n_x][n_y] = false;
	}
	return;
}

int main() {
	int i, j;
	cin.tie(NULL);
	cin >> r >> c >> k;

	for (i = 0; i < r; i++) {
		cin >> map[i];
	}

	visited[r - 1][0] = true;
	// 좌측 하단에서 출발
	DFS(1, r - 1, 0);

	cout << res << endl;

	return 0;
}
/*
BFS, DFS로 백트래킹 -> 경로의 길이가 K인 횟수 세면 된다.
사실상 브루트포스 -> 백트래킹
*/