/*
	Date: 2022/02/19
	Brief:
	simple brute force problem
	Reference:
*/
#include <iostream>
#define MAX 10001

using namespace std;

int arr[MAX];

bool check(int x) {
	int cnt = 0;
	int num;
	while (1) {
		num = x % 10;
		x /= 10;
		if (num == 6) {
			cnt++;
			if (cnt == 3) {
				return true;
			}
		}
		else {
			cnt = 0;
		}
		if (x == 0) break;
	}

	return false;
}

int main() {
	int n, cnt = 0;
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; ; i++) {
		if (check(i)) {
			arr[cnt++] = i;
		}
		if (cnt == 10000) break;
	}
	cout << arr[n - 1] << "\n";

	return 0;
}

/*
	��Ģ�� ���׹����̿��� �׳�
	���� ���� ������ Ȯ���ϸ鼭 666�� ����
	pattern matching�� ������ ���α׷��� �����ؾ�
	�� �� ���ٴ� ������ ��. (brute force �������)
*/