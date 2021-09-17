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
각 자리 숫자의 합이 3의 배수라면, 전체 숫자는 항상 3의 배수가 된다. 
- 정수론의 기초 개념 -

위 개념을 알고 있으면 쉽게 풀 수있는 문제입니다.
*/