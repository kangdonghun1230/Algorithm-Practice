#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 101

using namespace std;

string c[MAX][MAX];

// long long type�� �Ѿ�� ����� �����ϰ� ����ؾ� �ϱ� ������
// string���� ��ȯ�Ͽ� ����� ����ϴ� �Լ��� �ʿ��մϴ�.
string strNumAdd(string a, string b) {
	long long sum = 0;
	string result;

	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		// �ٽ� string type���� ����� push back
		result.push_back((sum % 10) + '0');
		// ���� �ڸ����� �ѱ��.
		sum /= 10;
	}
	// �������� �־��� ������ �������ش�.
	reverse(result.begin(), result.end());
	return result;
}

// �Ľ�Į�� �ﰢ�� ����� Ȱ���Ͽ� combination�� ������ش�.
string combination(int n, int m) {
	if (m == 0 || n == m) return "1";
	else if (c[n][m] != "") return c[n][m];
	else {
		// �ϳ��� ���� ���� ��� + �ϳ��� �����ϰ� �������� ���� ���
		return c[n][m] = strNumAdd(combination(n - 1, m - 1), combination(n - 1, m));
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		c[i][0] = "1";
		c[i][i] = "1";
	}

	cout << combination(n, m) << endl;

	return 0;
}