/*
	Date: 2022/02/17
	Brief:
	Simple problem solving with data structure (stack)
	Reference:
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int t, i;
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		string ps;
		stack<int> s;
		bool broken = false;
		cin >> ps;

		for (i = 0; i < ps.size(); i++) {
			if (ps[i] == '(') {
				s.push(1);
			}
			else {
				if (!s.empty())
					s.pop();
				else {
					broken = true;
					break;
				}
			}
		}
		if (s.empty() && !broken) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}