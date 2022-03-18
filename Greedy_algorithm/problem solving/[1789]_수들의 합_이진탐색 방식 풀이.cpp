#include <iostream>
#include <cmath>

using namespace std;

//int main() {
//	long s;
//	cin >> s;
//	// x�� 2 * s�� ������
//	// �뷫 x (x + 1) / 2�� �������� ���ؾ��ϱ� �����̴�.
//	long x = sqrt(2 * s);
//	long cnt = 0;
//	for (long i = x; i > 0; i--) {
//		// ���������� ���� ���ϴ� ������� �ִ� ������ ���Ѵ�.
//		if ((i * i + i) / 2 <= s) {
//			cnt = i;
//			break;
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}

int main() {
	long s;
	cin >> s;

	long cnt;
	long start = 1, end = s;
	// ���� ����� �״�� �����ϵ� �̺� Ž�� �������
	// sqrt�� ����� ���Ѵٰ� �����ϸ� �ȴ�.
	while (start <= end) {
		long mid = (start + end) / 2;
		if (mid * (mid + 1) / 2 <= s) {
			cnt = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << cnt << endl;
	return 0;
}