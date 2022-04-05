/*
	Date: 2022/04/05
	Brief:
	math problem solved by back tracking
	Reference:
*/
#include <iostream>

using namespace std;

int arr[14];
int res[7];
int k;

void DFS(int idx, int num) {
	if (num == 7) {
		for (int i = 1; i <= 6; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= k; i++) {
		res[num] = arr[i];
		DFS(i + 1, num + 1);
	}

	return;
}

int main() {
	int i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> k;

		if (k == 0) break;

		for (i = 1; i <= k; i++) {
			cin >> arr[i];
		}
		DFS(1, 1);
		cout << "\n";
	}

	return 0;
}