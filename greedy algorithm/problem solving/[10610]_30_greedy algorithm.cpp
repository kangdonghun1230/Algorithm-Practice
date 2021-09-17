#include <iostream>
#include <string>

using namespace std;

int d[10];

bool isMultipleOfThirty(string n) {
	int sum = 0;
	bool isZero = false;
	for (int i = 0; i < n.size(); i++) {
		sum += (n[i] - '0');
		if (n[i] == '0') isZero = true;
	}

	if (sum % 3 == 0 && isZero) return true;
	else return false;
}

int main() {
	string n;
	cin >> n;

	if (!isMultipleOfThirty(n)) {
		cout << -1 << "\n";
		return 0;
	}

	for (int i = 0; i < n.size(); i++) {
		d[n[i] - '0']++;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < d[i]; j++) {
			cout << i;
		}
	}cout << endl;

	return 0;
}

/*
�� �ڸ� ������ ���� 3�� ������, ��ü ���ڴ� �׻� 3�� ����� �ȴ�. 
- �������� ���� ���� -

�� ������ �˰� ������ ���� Ǯ ���ִ� �����Դϴ�.
*/