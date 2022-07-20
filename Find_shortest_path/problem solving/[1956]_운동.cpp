/*
	Date: 2022/07/20
	Brief:
	Floyd-Warshall algorithm
	Reference:
*/
#include <iostream>
#define MAX 401
#define INF 4000001

using namespace std;

int v, e;
int arr[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		arr[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	int res = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)
				continue;
			else {
				res = (res > arr[i][j] + arr[j][i]) ? arr[i][j] + arr[j][i] : res;
			}
		}
	}

	if (res == INF) {
		cout << -1;
	}
	else {
		cout << res;
	}
	return 0;
}