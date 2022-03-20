/*
	Date: 2022/03/20
	Brief:
	cumulative sum, prefix sum (누적 합)
	Reference:
	https://twpower.github.io/157-prefix-sum-basic-problem
	생각보다 그냥 구현하는 문제였음.
*/
#include <iostream>
#define MAX 100001

using namespace std;

int arr[MAX];
int accumulation[MAX];

int main() {
	int n, m;
	int i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		accumulation[i] = accumulation[i - 1] + arr[i];
	}

	while (m--) {
		int from, to;
		cin >> from >> to;

		cout << accumulation[to] - accumulation[from - 1] << "\n";
	}

	return 0;
}