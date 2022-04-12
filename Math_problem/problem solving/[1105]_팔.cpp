/*
	Date: 2022/04/12
	Brief:
	math problem + implementation
	Reference:
*/
#include <iostream>
#include <string>

using namespace std;


int main() {
	string l, r;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> r;

	if (l.length() != r.length()) {
		cout << "0\n";
		return 0;
	}

	int len = l.length();
	int cnt = 0;

	for (int i = 0; i < len; i++) {
		if (l[i] == r[i] && l[i] == '8')
			cnt++;
		else if (l[i] == r[i])
			continue;
		else
			break;
	}

	cout << cnt << "\n";

	return 0;
}
/*
�� ���� �ڸ����� �ٸ��� -> 0
�� ���� �ڸ����� ������ -> 
1. ���� ū �ڸ������� Ž�� 8�� ������ �������� ��.
2. 8�� �ƴ� �ٸ� ���� ���� ��쿡�� ���� �ڸ����� ž��
3. �ش� �ڸ������� ���ڰ� �ٸ� ��� Ž�� ���� -> �� �̻� 8�� ������ �ʿ� ����
*/