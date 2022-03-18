/*
	Date: 2022/02/03
	Brief:
	Simple dynamic programming example
	Reference:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 100000

using namespace std;

int dp[2][MAX];
int a[2][MAX];

int calculateMax(int n) {
	// 현재 케이스를 선택하는 조건은 무적건 3가지 케이스 중 하나에 해당할 것이다.
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < n; j++) {
			dp[i][j] = a[i][j];
		}
	}

	dp[0][1] += dp[1][0];
	dp[1][1] += dp[0][0];

	for (i = 2; i < n; i++) {
		int tmp;

		/* dp[0][i]를 갱신 */
		tmp = max(dp[0][i] + dp[1][i - 2], dp[0][i] + dp[0][i - 2]);

		if (tmp > dp[0][i] + dp[1][i - 1]) {
			dp[0][i] = tmp;
		}
		else {
			dp[0][i] += dp[1][i - 1];
		}

		/* dp[1][i]를 갱신 */
		tmp = max(dp[1][i] + dp[1][i - 2], dp[1][i] + dp[0][i - 2]);

		if (tmp > dp[1][i] + dp[0][i - 1]) {
			dp[1][i] = tmp;
		}
		else {
			dp[1][i] += dp[0][i - 1];
		}
	}

	return max(dp[0][n-1], dp[1][n-1]);
}

int main() {
	int n, T;
	int i, j, k;
	int tmp;
	cin.tie(NULL);

	cin >> T;

	for (i = 0; i < T; i++) {
		cin >> n;
		// get the sticker information
		for (j = 0; j < 2; j++) {
			for (k = 0; k < n; k++) {
				cin >> a[j][k];
			}
		}
		cout << calculateMax(n) << "\n";
		memset(a[0], 0, sizeof(int) * n);
		memset(a[1], 0, sizeof(int) * n);
	}

	return 0;
}
