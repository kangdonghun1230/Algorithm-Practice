/*
	Date: 2022/04/01
	Brief:
	math? sort
	Reference:
	just sort array and calculate the multiple of first and last number
*/
#include <iostream>
#include <cmath>
#define MAX 1000000000

using namespace std;

// calculate the current win ratio.
int calWinRatio(long long x, long long y) {
	int ratio = (y * 100) / x;

	return ratio;
}

int main() {
	long long x, y;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;

	int z = calWinRatio(x, y);
	int winRatioAfterChange = z;

	//cout << z << "\n";

	if (z == 99 || x == y) {
		cout << "-1\n";
		return 0;
	}

	// 1퍼센트 기준치를 구해서 범위 계속해서 반씩 좁히는 느낌으로 가면 될듯
	long long start = 1;
	long long end = MAX;

	while (start < end) {
		long long mid = (start + end) / 2;
		winRatioAfterChange = calWinRatio(x + mid, y + mid);

		if (winRatioAfterChange > z) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	cout << start << " " << end << "\n";
	
	return 0;
}