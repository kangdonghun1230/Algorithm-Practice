/*
	Date: 2022/04/16
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#define MAX 1001

using namespace std;

// first dimension: the length of the number
// second dimension: last number of the number
int dp[MAX][10];

int main() {
	int n;
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0];
		for (j = 1; j < 10; j++) {
			// length i + last number j -> length i-1 last number  0~j + length i-1 last number j
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	int res = 0;
	for (i = 0; i < 10; i++) {
		res += dp[n][i];
		res %= 10007;
	}

	cout << res << "\n";

	return 0;
}