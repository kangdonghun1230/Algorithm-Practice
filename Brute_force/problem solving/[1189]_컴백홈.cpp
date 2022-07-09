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
	// k�� �̵��ؼ� ������ ������ ��� (���� ����� ����)
	if (cnt == k && x == 0 && y == (c - 1)) {
		res++;
		return;
	}
	// k�� �̵��ߴµ� ������ ������ ���
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
	// ���� �ϴܿ��� ���
	DFS(1, r - 1, 0);

	cout << res << endl;

	return 0;
}
/*
BFS, DFS�� ��Ʈ��ŷ -> ����� ���̰� K�� Ƚ�� ���� �ȴ�.
��ǻ� ���Ʈ���� -> ��Ʈ��ŷ
*/