/*
	Date: 2022/02/01
	Brief:
	Simple program for calculating section sum of 2d matrix
	Reference:
*/
#include <iostream>
#define MAX 301

using namespace std;

int a[MAX][MAX];
// (1, 1) ~ (i, j) 영역에 해당하는 사각형 영역내의 모든 수의 합
int dp[MAX][MAX];

void init(int n, int m) {
	int i, j;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// (1, 1) ~ (i, j)의 영역에 해당하는 사각형 내의 모든 수의 합
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];
		}
	}
	return;
}

int main() {
	int n, m, k;
	int i, j, x1, y1, x2, y2;
	int sectionSum;
	cin.tie(NULL);

	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	init(n, m);
	// k: the number of calculation
	cin >> k;

	for (i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		// 두 사각형이 커버하고 있는 범위를 생각하면 이해가 쉽다.
		sectionSum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		// print the section sum
		cout << sectionSum << endl;
	}


	return 0;
}