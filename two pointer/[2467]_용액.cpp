/*
	Date: 2022/03/02
	Brief:
	problem using two pointer algorithm?
	Reference:
	https://jaimemin.tistory.com/1296
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, i;
	vector<int> v;
	cin.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int start = 0, end = v.size() - 1, res = 2e9;
	pair<int, int> result;

	while (start < end) {
		int a = v[start];
		int b = v[end];

		if (abs(a + b) < res) {
			res = abs(a + b);
			result.first = start;
			result.second = end;
		}

		if (a + b > 0) {
			end--;
		}
		else if (a + b < 0) {
			start++;
		}
		else
			break;
	}

	cout << v[result.first] << " " << v[result.second] << "\n";


	return 0;
}