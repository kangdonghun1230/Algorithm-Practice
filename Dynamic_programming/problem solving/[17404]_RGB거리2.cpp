/*
	Date: 2022/03/03
	Brief:
	dynamic programming
	Reference:

*/
#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int paintFee[MAX][3];
int dpRes[MAX][3]; // save the minimum cost of current status

int main() {
	int n, i, j;
	cin.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> paintFee[i][0] >> paintFee[i][1] >> paintFee[i][2];
	}
	int result = MAX * MAX;

	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= 2; j++) {
			if (i == j) {
				dpRes[0][j] = paintFee[0][j];
			}
			else {
				dpRes[0][j] = MAX * MAX; // maximum value
			}
		}
		for (j = 1; j < n; j++) {
			dpRes[j][0] = min(dpRes[j - 1][1], dpRes[j - 1][2]) + paintFee[j][0];
			dpRes[j][1] = min(dpRes[j - 1][0], dpRes[j - 1][2]) + paintFee[j][1];
			dpRes[j][2] = min(dpRes[j - 1][1], dpRes[j - 1][0]) + paintFee[j][2];
		}

		for (j = 0; j <= 2; j++) {
			if (i == j) continue; // skip the case of start == end
			result = min(result, dpRes[n - 1][j]);
		}
	}

	cout << result << "\n";

	return 0;
}