/*
	Date: 2022/02/01
	Brief:
	Simple program for calculating section sum of 2d matrix
	Reference:https://sihyungyou.github.io/baekjoon-2167/
*/

#include <iostream>
#define MAX 1025

using namespace std;

int a[MAX][MAX];
// (1, 1) ~ (i, j) 영역에 해당하는 사각형 영역내의 모든 수의 합
int dp[MAX][MAX];

void init(int n) {
	int i, j;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// (1, 1) ~ (i, j)의 영역에 해당하는 사각형 내의 모든 수의 합
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];
		}
	}
	return;
}

int main() {
	int n, m, x1, y1, x2, y2;
	int i, j;
	int sectionSum;
	cin.tie(NULL);
	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	init(n);

	for (i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		sectionSum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		// print the section sum
		cout << sectionSum << '\n';
	}

	return 0;
}