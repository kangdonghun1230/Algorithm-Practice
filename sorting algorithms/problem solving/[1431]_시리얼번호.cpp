#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str[1001];

int getSum(string a) {
	int a_sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if ('0' <= a[i] && a[i] <= '9') a_sum += (a[i] - '0');
	}

	return a_sum;
}

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else {
		int a_sum = getSum(a), b_sum = getSum(b);

		// serial number 작은 순
		if (a_sum != b_sum)
			return a_sum < b_sum;
		// 비교 안되면 사전 순
		else
			return a < b;
	}
}

int main() {
	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> str[i];
	}

	sort(str, str + num, compare);

	for (int i = 0; i < num; i++)
		cout << str[i] << endl;

	return 0;
}