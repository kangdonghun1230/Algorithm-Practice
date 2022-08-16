/*
	Date: 2022/08/16
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int n;
int dp[MAX][2];
int arr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}

	int res = 0;

	for (int i = 0; i < n; i++) {
		// 자기 자신까지 길이에 포함시켜야 한다.
		res = max(res, dp[i][0] + dp[i][1] + 1);
	}

	cout << res << "\n";

	return 0;
}

/*
두 개의 파트로 나눠서 dp로 구현해야
1. 증가하는 입장에서 기록하며
2. 감소하는 입장에서 기록하며

두 개를 합쳐서 가장 큰 값을 갖는 부분을 뽑는다.
*/