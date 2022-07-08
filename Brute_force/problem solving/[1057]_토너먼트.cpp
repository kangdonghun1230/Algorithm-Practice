/*
	Date: 2022/07/08
	Brief:
	Brute-Force
	Reference:
*/
#include <iostream>

using namespace std;

int n;

int main() {
	int kim, im;

	cin.tie(NULL);
	cin >> n >> kim >> im;

	kim -= 1; im -= 1;

	int num = 20;
	int cnt = 1;
	while (num--) {
		if ((kim / 2) == (im / 2)) {
			cout << cnt << "\n";
			break;
		}

		cnt++;
		kim = (kim / 2);
		im = (im / 2);
	}

	return 0;
}

/*
           1
       1        2
   1       2        3
 1   2   3   4   5
1 2 3 4 5 6 7 8 9

2�� ���� �� + 1�� ������ �ο����� ��ȣ��� ������ �� �ִ�.
����ؼ� �����ٰ� 2�� ���� ���� �������� ��� ���� ��� �����ٰ� �Ǵ��� �� �ִ�.
*/