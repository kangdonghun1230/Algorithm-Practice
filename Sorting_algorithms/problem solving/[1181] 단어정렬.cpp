#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str[20001];

bool compare(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
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

	for (int i = 0; i < num; i++) {
		if (str[i] == str[i - 1]) continue;
		cout << str[i] << endl;
	}

	return 0;
}