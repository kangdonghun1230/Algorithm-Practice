/*
	Date: 2022/04/27
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#define MAX 300000

using namespace std;

int triangle[131];

int dp[MAX];

int main() {
	int i, j;
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (i = 1; i <= 130; i++) {
		// cur = sum of (1 ~ i)
		int cur = i * (i + 1) / 2;
		triangle[i] = triangle[i - 1] + cur;
	}

	cin >> n;

	int start = 0, end = 130;

	for (i = 1; i <= n; i++) {
		dp[i] = 131;
	}

	for (i = 1; i <= n; i++) {
		for (j = 130; j >= 1; j--) {
			if (i - triangle[j] >= 0) {
				dp[i] = min(dp[i - triangle[j]] + 1, dp[i]);
			}
		}
	}

	cout << dp[n] << "\n";

	return 0;
}