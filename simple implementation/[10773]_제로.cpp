#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;
	int k, i;
	cin.tie(NULL);

	cin >> k;

	for (i = 0; i < k; i++) {
		int num;
		cin >> num;

		if (num == 0 && !s.empty()) {
			s.pop();
		}
		else if(num != 0) {
			s.push(num);
		}
		else {
			continue;
		}
	}
	int sum = 0;

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << "\n";

	return 0;
}