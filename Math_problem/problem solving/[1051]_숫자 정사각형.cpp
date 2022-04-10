/*
	Date: 2022/04/10
	Brief:
	math problem + implementation
	Reference:
*/
#include <iostream>
#define MAX 51

using namespace std;

string arr[MAX];

// check if the current distance make sure that square
bool checkSquare(int x, int y, int dis) {
	int num = arr[x][y];

	if (num == arr[x + dis][y] && num == arr[x + dis][y + dis] && num == arr[x][y + dis])
		return true;
	else
		return false;
}

int main() {
	int n, m;
	int i, j, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int cur_max = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int max_dis = (n - i - 1 > m - j - 1) ? m - j - 1 : n - i - 1;

			for (k = max_dis; k >= 1; k--) {
				if (checkSquare(i, j, k))
					cur_max = (cur_max < k + 1) ? k + 1 : cur_max;
			}
		}
	}

	cout << cur_max * cur_max << "\n";


	return 0;
}