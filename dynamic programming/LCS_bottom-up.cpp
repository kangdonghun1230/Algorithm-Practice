/*
	Date: 2022/03/12
	Brief:
	LCS example 2 + get one LCS example of two strings.
	top down memoization method.
	Reference:
*/
#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001


using namespace std;

int n, m;
int c[MAX][MAX];

void LCSInit(string x, string y) {
	int i;
	m = x.length();
	n = y.length();

	for (i = 1; i <= m; i++) {
		c[i][0] = 0;
	}

	for (i = 1; i <= n; i++) {
		c[0][i] = 0;
	}

	return;
}

int LCSLength(string x, string y) {
	//// If one of two indices are zero, return current function.
	//if (i == 0 || j == 0) return c[i][j];
	//// return current value which is already initialized.
	//else if (c[i][j] != 0) return c[i][j];
	//
	//if (x[i - 1] == y[j - 1]) {
	//	c[i][j] = LCSLength(x, y, i - 1, j - 1) + 1;
	//}
	//else {
	//	c[i][j] = max(LCSLength(x, y, i - 1, j), LCSLength(x, y, i, j - 1));
	//}
	int i, j;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else {
				c[i][j] = max(c[i][j - 1], c[i - 1][j]);
			}
		}
	}

	return c[m][n];
}

void getLCS(string x, string y, int i, int j) {
	string res;

	while (i > 0 && j > 0) {
		if (c[i][j] == c[i - 1][j]) {
			i--;
		}
		else if (c[i][j] == c[i][j - 1]) {
			j--;
		}
		else {
			res += x[i - 1];
			i--; j--;
		}
	}
	
	for (int k = res.length() - 1; k >= 0; k--) {
		cout << res[k];
	}
	cout << "\n";
	return;
}

int main() {
	string x, y;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;

	LCSInit(x, y);
	int len = LCSLength(x, y);
	cout << len << "\n";

	// print the LCS example, when LCS length of two strings are not zero.
	if(len)
		getLCS(x, y, m, n);

	return 0;
}
