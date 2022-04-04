/*
	Date: 2022/04/04
	Brief:
	math problem solving with dynamic programming
	Reference:
*/
#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int square[MAX];
int arr[MAX];
int len;

int getSquareNum(int x) {
	int i;
	square[1] = 1;
	for (i = 2; i * i <= x; i++) {
		square[i] = i * i;
	}
	int len = i - 1;
	return len;
}

void dp(int x) {
	for (int i = 1; i <= x; i++) {
		arr[i] = MAX;
	}

	arr[1] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = len; j >= 1; j--) {
			if (i - square[j] >= 0) {
				arr[i] = min(arr[i], arr[i - square[j]] + 1);
			}
		}
	}

	return;
}

int main() {
	int N;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	len = getSquareNum(N);

	dp(N);

	cout << arr[N] << "\n";

	return 0;
}