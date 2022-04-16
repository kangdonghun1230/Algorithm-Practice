/*
	Date: 2022/04/16
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#include <algorithm>

#define MAX 10001

using namespace std;

int arr[MAX];
int dp[MAX];

int main() {
	int n;
	int i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	// 마찬가지로 세 번째 잔도, 포함/미포함의 경우를 모두 살펴야 한다.
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	dp[2] = max(dp[2], dp[1]);
	for (i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		// 현재 포도주를 마시지 않는 경우가 더 클 때
		dp[i] = max(dp[i], dp[i - 1]);
	}
	
	cout << dp[n - 1] << "\n";

	return 0;
}