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
		// �ڱ� �ڽű��� ���̿� ���Խ��Ѿ� �Ѵ�.
		res = max(res, dp[i][0] + dp[i][1] + 1);
	}

	cout << res << "\n";

	return 0;
}

/*
�� ���� ��Ʈ�� ������ dp�� �����ؾ�
1. �����ϴ� ���忡�� ����ϸ�
2. �����ϴ� ���忡�� ����ϸ�

�� ���� ���ļ� ���� ū ���� ���� �κ��� �̴´�.
*/