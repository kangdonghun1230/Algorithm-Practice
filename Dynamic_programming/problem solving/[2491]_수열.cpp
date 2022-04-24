/*
	Date: 2022/04/22
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#define MAX 100001

using namespace std;

int arr[MAX];
int dp1[MAX];
int dp2[MAX];

int main() {
	int n;
	int i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp1[0] = 1;
	dp2[0] = 1;
	int res = 1;
	for (i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			dp1[i] = dp1[i - 1] + 1;
		}
		else {
			dp1[i] = 1;
		}
		if (arr[i] <= arr[i - 1]) {
			dp2[i] = dp2[i - 1] + 1;
		}
		else {
			dp2[i] = 1;
		}
		res = (res < dp1[i]) ? dp1[i] : res;
		res = (res < dp2[i]) ? dp2[i] : res;
	}

	cout << res << "\n";

	return 0;
}