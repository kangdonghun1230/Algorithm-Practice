/*
	Date: 2021/11/19
	Brief:
	Implement the LCS algorithm program with top-down memoized 
	dynamic	programming.
*/
#include <iostream>
#include <string>
#include <algorithm> /* max */
// maximum n, m value is 7
#define MAX 8

using namespace std;

// length of sequence Y, X
int n, m;

int c[MAX][MAX];

/*
	function name: LCS_Init
	brief:
	set the array c's value about empty sequence
	c[1~m][0] = 0, c[0][1~n] = 0
*/
void LCS_Init(string X, string Y) {
	n = Y.length();
	m = X.length();

	// the case of j == 0
	for (int i = 1; i < m; i++) {
		c[i][0] = 0;
	}
	// the case of i == 0
	for (int i = 1; i < n; i++) {
		c[0][i] = 0;
	}

	return;
}
/*
	function name: LCS_Length
	brief:
	get the length of LCS of two sequences (X, Y)
	with top-down memoization calling current function
	recursively
*/
int LCS_Length(string X, string Y, int i, int j) {
	// if one of two sequences is empty sequence
	if (i == 0 || j == 0)
		return c[i][j];
	// if this sub problem is already solved, return the saved value
	else if (c[i][j] != 0)
		return c[i][j];
	// last two elements are same
	if (X[i - 1] == Y[j - 1]) {
		c[i][j] = LCS_Length(X, Y, i - 1, j - 1) + 1;
	}
	// last two elements are different
	else {
		c[i][j] = max(LCS_Length(X, Y, i - 1, j), LCS_Length(X, Y, i, j - 1));
	}

	return c[i][j];
}

int main() {
	string X, Y;
	cin >> X >> Y;

	LCS_Init(X, Y);
	int res = LCS_Length(X, Y, m, n);

	cout << "LCS Length: " << res << endl;

	return 0;
}