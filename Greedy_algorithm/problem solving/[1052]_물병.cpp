/*
	Date: 2022/03/28
	Brief:
	greedy algorithm
	Reference:
	https://yabmoons.tistory.com/199
*/
#include <iostream>

using namespace std;

// x���� ���� �ִ��� ������ ���� ������ return�ϴ� �Լ��Դϴ�.
int calBottle(int x) {
	int cnt = 0;
	while (x > 0) {
		// 2�� ������ 1�� ���� ��� -> ���� �ܰ迡�� ��ĥ �� ���� ���� �ǹ�
		if (x % 2 == 1)
			cnt++;
		x /= 2;
	}
	return cnt;
}

int main() {
	int i, j;
	int n, k;
	int cnt;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	int needBottle = 0;

	if (n <= k) {
		cout << "0\n";
		return 0;
	}

	while (1) {
		int tmp = calBottle(n);
		if (tmp <= k) break;

		n++;
		needBottle++;
	}

	cout << needBottle << "\n";

	return 0;
}