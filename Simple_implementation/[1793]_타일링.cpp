/*
	Date: 2022/06/30
	Brief:
	Implementation
	Reference:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#define MAX 251

using namespace std;

string d[MAX];

string strConcat(string a, string b) {
	int len;
	// len is longer string's length
	if (a.length() < b.length())
		swap(a, b);
	
	len = b.length();

	// a is longer one
	for (int i = 0; i < len; i++) {
		int num = (a[i] - '0') + (b[i] - '0');

		if (num >= 10) {
			a[i] = num - 10 + '0';

			// 다음 자리수로 넘어가야 하는 경우
			if (i == (int)(a.length() - 1)) a.push_back('1');
			else a[i + 1]++;
		}
		else {
			a[i] = num + '0';
		}
	}
	return a;
}

string dp(int n) {
	if (!d[n].empty()) return d[n];
	for (int i = 3; i <= n; i++) {
		d[i] = strConcat(strConcat(dp(i - 1), dp(i - 2)), dp(i - 2));
	}
	return d[n];
}

int main() {
	int n;

	d[0] = '1';
	d[1] = '1';
	d[2] = '3';


	while(scanf("%d", &n) == 1) {
		string res = dp(n);

		reverse(res.begin(), res.end());
		cout << res << "\n";
	}

	return 0;
}
/*
2x1, 2x2 두 개의 타일이 존재.
2xn 직사각형을 타일로 채우는 방법의 가지 수를 구하는 문제이다.
*/