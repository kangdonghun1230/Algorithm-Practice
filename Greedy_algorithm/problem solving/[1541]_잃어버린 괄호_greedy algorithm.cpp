#include <iostream>
#include <string>

using namespace std;

int main() {
	string equation;
	cin >> equation;
	string tmp;

	bool isMinus = false;
	int result = 0;
	// string�� '\0'���� �����ϱ� ���� ���� ����
	for (int i = 0; i <= equation.size(); i++) {
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '\0') {
			if (isMinus) {
				result -= stoi(tmp);
			}
			else {
				result += stoi(tmp);
			}
			if (equation[i] == '-') {
				isMinus = true;
			}
			tmp = "";
			continue;
		}
		// tmp�� ��ȣ ������ ���ڸ� ����
		tmp += equation[i];
	}

	cout << result << endl;

	return 0;
}