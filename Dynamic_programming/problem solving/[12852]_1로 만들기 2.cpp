/*
	Date: 2022/03/16
	Brief:
	simple dynamic programming example
	Reference:
*/
#include <iostream>
#include <algorithm>
#define MAX 1000001

using namespace std;

int dp[MAX][2];

int main() {
	int n, i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dp[2][0] = 1, dp[3][0] = 1;
	dp[2][1] = 1, dp[3][1] = 1;
	for (i = 4; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + 1;
		dp[i][1] = i - 1;
		if (i % 3 == 0 && dp[i][0] > dp[i/3][0] + 1) {
			dp[i][0] = dp[i / 3][0] + 1;
			dp[i][1] = i / 3;
		}
		if (i % 2 == 0 && dp[i][0] > dp[i / 2][0] + 1) {
			dp[i][0] = dp[i / 2][0] + 1;
			dp[i][1] = i / 2;
		}
	}

	cout << dp[n][0] << "\n";

	int p = n;
	while (p != 0) {
		cout << p << " ";
		p = dp[p][1];
	}

	return 0;
}