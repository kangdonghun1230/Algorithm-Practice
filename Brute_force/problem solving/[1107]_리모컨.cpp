/*
	Date: 2022/03/25
	Brief:
	Brute-force example
	���� ���Ʈ ������ ���� ���� �� ����. ���� ����� �˾����� �����ؼ� Ǯ����.
	Reference:
	https://seol-limit.tistory.com/48
*/
#include <iostream>
#include <cmath>

using namespace std;

bool isBroken[10];

bool checkNum(int x) {
	if (x == 0 && isBroken[0]) {
		return false;
	}
	else if (x == 0 && !isBroken[0]) {
		return true;
	}
	while (x > 0) {
		// �ϳ��� �μ��� ��ư�� ��� return false
		if (isBroken[x % 10])
			return false;
		x /= 10;
	}
	return true;
}

int getLen(int x) {
	int len = 0;
	if (x == 0) return 1;
	while (x > 0) {
		x /= 10;
		len++;
	}
	return len;
}

int main() {
	int n, m;
	int i, j;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> m;

	for (i = 0; i < m; i++) {
		int num;
		cin >> num;
		isBroken[num] = true;
	}
	// start channel number is 100
	int res = abs(n - 100);
	for (i = 0; i <= 1000000; i++) {
		int num = i;
		if (!checkNum(num)) continue;
		int len = getLen(num);
		// initialize res with conditional operator
		res = res > abs(num - n) + len ? abs(num - n) + len : res;
	}

	cout << res << "\n";

	return 0;
}