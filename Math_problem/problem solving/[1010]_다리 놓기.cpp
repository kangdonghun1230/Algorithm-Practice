/*
	Date: 2022/03/29
	Brief:
	sieve of eratosthenes maybe
	Reference:
*/
#include <iostream>
#define MAX 31

using namespace std;

// calcualte combination with two channel matrix
long long comb[MAX][MAX];

/*
long long combination(int n, int r) {
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r); // 하나 뽑고 시작 or 하나 제외하고 뽑기
}
*/

long long combination(int n, int r) {
	for (int i = 1; i <= 30; i++) {
		comb[i][i] = 1;
		comb[i][1] = i;
	}

	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j <= 30; j++) {
			if (i > j) {
				// nCr = n-1Cr + n-1Cr-1
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			}
		}
	}

	return comb[n][r];
}

int main() {
	int t;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;

		cout << combination(m, n) << "\n";
	}


	return 0;
}