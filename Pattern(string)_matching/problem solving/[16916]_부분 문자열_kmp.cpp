#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size(), j = 0;
	// patternSize만큼 0으로 초기화한다.
	vector<int> table(patternSize, 0);

	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			// 일치하지 않는 경우 index를 옮긴다.
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			// 일치하는 경우 j index + 1
			table[i] = ++j;
		}
	}
	return table;
}

vector<int> kmp(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	vector<int> result;
	int parentSize = parent.size(), patternSize = pattern.size(), j = 0;

	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				result.push_back(i);
				j = table[j];
			}
			else
				j++;
		}
	}

	return result;
}

int main() {
	string parent, pattern;

	cin >> parent >> pattern;

	auto result = kmp(parent, pattern);

	if (result.size() != 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

	return 0;
}