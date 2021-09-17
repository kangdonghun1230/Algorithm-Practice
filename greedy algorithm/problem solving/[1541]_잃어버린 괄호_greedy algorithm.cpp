#include <iostream>
#include <string>

using namespace std;

int main() {
	string equation;
	cin >> equation;
	string tmp;

	bool isMinus = false;
	int result = 0;
	// string의 '\0'까지 도달하기 위한 범위 설정
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
		// tmp는 부호 사이의 숫자를 저장
		tmp += equation[i];
	}

	cout << result << endl;

	return 0;
}