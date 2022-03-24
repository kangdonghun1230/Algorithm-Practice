/*
	Date: 2022/03/24
	Brief:
	simple dynamic programming problem
	Reference:
*/
#include <iostream>
#define MAX 101

using namespace std;

// ���� �������� int type���� ǥ�� ������ ������ ����� �����̴�.
long long p[MAX] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

int main() {
	int t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 11; i < MAX; i++) {
		p[i] = p[i - 1] + p[i - 5];
	}

	cin >> t;

	while (t--) {
		int x;
		cin >> x;
		cout << p[x] << "\n";
	}


	return 0;
}