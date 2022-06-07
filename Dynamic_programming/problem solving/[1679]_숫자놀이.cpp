/*
	Date: 2022/06/07
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#include <algorithm>
#include <string>

#define MAX 50001
#define MAX_N 1001
#define MAX_K 51

using namespace std;

int dp[MAX];
int arr[MAX_N];

int main() {
	int n, k;
	int res = 0;
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= MAX; i++) {
		dp[i] = MAX_K;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}
	cin >> k;

	for (int i = 1; i <= MAX; i++) {
		for (int j = 0; j < n; j++) {
			if(i - arr[j] > 0)
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}

		if (dp[i] > k) {
			res = i;
			break;
		}
	}

	string str = (res % 2 == 0) ? "holsoon win at " : "jjaksoon win at ";
	cout << str << res << "\n";


	return 0;
}