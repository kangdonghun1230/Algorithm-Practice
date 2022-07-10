/*
	Date: 2022/07/10
	Brief:
	set + implementation
	Reference:
	https://beginnerdeveloper-lit.tistory.com/142
*/
#include <iostream>
#include <algorithm> // reverse()
#include <string>
#include <vector>
#include <set> // set data structure

#define MAX 1001

using namespace std;

string numArr[MAX];
int n;

int main() {
	int i, j;

	cin.tie(NULL);
	cin >> n;

	for (i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		numArr[i] = tmp;
	}

	int len = numArr[0].length();
	int res = len;

	for (i = 1; i <= len; i++) {
		// set -> 중복된 member 추가 불가능하다.
		set<string> s;

		for (j = 0; j < n; j++) {
			// string.substr(pos, count)
			s.insert(numArr[j].substr(0, i));
		}

		// set 자료구조에 n개만큼 import된 경우 성공
		if (s.size() == n) {
			res = i;
			break;
		}
		else {
			continue;
		}
	}

	cout << res << "\n";

	return 0;
}