#include <iostream>
#include <algorithm>
#define MAX 201
#define MOD 1000000000

using namespace std;

// 1차원: 수, 2차원: n가지 수로 만드는 경우의 수
int arr[MAX][MAX];
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		arr[i][1] = 1;
	}

	// i는 만들려고 하는 수
	for (int i = 0; i <= n; i++) {
	// r은 현재 가지 수
		for (int r = 2; r <= k; r++) {
	// j는 0 ~ i 사이의 수
			for (int j = 0; j <= i; j++) {
				// i를 r가지 수로 만드는 방법 = i-j를 r-1 가지 수로 만들기 + j 더하기
				arr[i][r] += arr[i - j][r - 1];
				arr[i][r] %= MOD; // modulo 연산
			}
		}
	}

	// n이라는 수를, k가지의 수를 이용해 만드는 경우의 수
	cout << arr[n][k] % MOD;

	return 0;
}