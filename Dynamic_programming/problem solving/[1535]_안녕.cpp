/*
	Date: 2022/04/16
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#include <algorithm>
#define MAX 21

using namespace std;

// Life, Joy
int L[MAX], J[MAX];
int dp[MAX][101];

int main() {
	int n;
	int i, j;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> L[i];
	}
	for (i = 0; i < n; i++) {
		cin >> J[i];
	}
	dp[0][100 - L[0]] = J[0];

	// if first person's life for greeting is 100, then initial res value is 0
	// if not initial res value is J[0]
	int res = (L[0] == 100) ? 0 : J[0];

	// i means the index of person
	for (i = 1; i < n; i++) {
		// j directs the life count of current status
		for (j = 100; j > 0; j--) {
			if (j + L[i] <= 100) // affording to greet i th person
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + L[i]] + J[i]);
			else // don't have enough life for greeting i th person
				dp[i][j] = dp[i - 1][j];

			if (i == n - 1) {
				res = max(res, dp[n - 1][j]);
			}
		}
	}


	cout << res << "\n";


	return 0;
}