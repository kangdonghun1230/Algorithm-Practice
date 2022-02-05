/*
	Date: 2022/02/05
	Brief:
	simple math problem with map data structure
	Reference:
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
	int t, n, result = 1;
	int i, j;
	cin.tie(NULL);

	cin >> t;


	while (t--) {
		map<string, int> m;
		cin >> n;
		
		string name, type;
		for (i = 0; i < n; i++) {
			cin >> name >> type;
			// value += 1
			m[type]++;
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			// n+1C1 -> n가지의 옷 + 아무것도 입지 않는 경우
			result *= (it->second + 1);
		}
		// 알몸이 되는 경우
		result -= 1;

		cout << result << "\n";
		result = 1;
	}

	return 0;
}