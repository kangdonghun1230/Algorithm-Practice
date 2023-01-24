#include <iostream>
#define MAX 101

using namespace std;

int arr[MAX][MAX];
long long d[MAX][MAX];
int n;

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = -1;
		}
	}
}

long long dfs(int x, int y) {
	int dx[] = { 1, 0 };
	int dy[] = { 0, 1 };

	int curNode = arr[x][y];

	if (x == n - 1 && y == n - 1) {
		return 1;
	}

	if (d[x][y] != -1)
		return d[x][y];
	d[x][y] = 0;

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i] * curNode;
		int ny = y + dy[i] * curNode;

		if (!inRange(nx, ny))
			continue;

		d[x][y] += dfs(nx, ny);
	}

	return d[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	init();

	cout << dfs(0, 0);

	return 0;
}