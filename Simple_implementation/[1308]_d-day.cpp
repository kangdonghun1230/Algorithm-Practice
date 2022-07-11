/*
	Date: 2022/07/11
	Brief:
	greedy algorithm
	Reference:
*/
#include <iostream>
#include <string>

using namespace std;

int mons[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int y) {
	if (y % 4 != 0) return false;
	else if (y % 100 != 0) return true;
	else if (y % 400 == 0) return true;
	else return false;
}

int calDays(int y, int m, int d) {
	int res = 0;

	for (int i = 1; i < y; i++) {
		res += (365 + isLeapYear(i));
	}
	for (int i = 1; i < m; i++) {
		if (i == 2)
			res += isLeapYear(y);
		res += mons[i - 1];
	}
	res += d;

	return res;
}
int cal(int y, int M) {
	int r = 0;
	for (int i = 1; i <= y; ++i) {
		for (int j = 0; j < (i == y ? M - 1 : 12); ++j) {
			r += mons[j];
			if (j == 1 && ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))) {
				++r;
			}
		}
	}
	return r;
}


int main() {
	int year1, year2;
	int mon1, mon2;
	int day1, day2;

	cin.tie(NULL);
	cin >> year1 >> mon1 >> day1;
	cin >> year2 >> mon2 >> day2;

	int res1 = calDays(year1, mon1, day1);
	int res2 = calDays(year2, mon2, day2);

	int days1000 = calDays(1001, 1, 0);
	int ans = res2 - res1;

	//cout << days1000 << " " << cal(1001, 1) << endl;

	//cout << res1 << " " << res2 << endl;
	if (ans > days1000)
		cout << "gg\n";
	else
		cout << "D-" << ans << "\n";


	return 0;
}

/*
1: 31
2: 28 À±³â -> 29
3: 31
4: 30
5: 31
6: 30
7: 31
8: 31
9: 30
10: 31
11: 30
12: 31
*/