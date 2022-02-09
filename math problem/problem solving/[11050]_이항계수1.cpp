/*
	Date: 2022/02/09
	Brief:
	simple math problem
	Reference:
*/
#include <iostream>

using namespace std;

int fact(int x) {
	int res = 1;
	for (int i = 1; i <= x; i++) {
		res *= i;
	}
	return res;
}

int main() {
	int n, k;
	cin.tie(NULL);
	cin >> n >> k;

	int result = fact(n) / (fact(k) * fact(n - k));

	cout << result << "\n";

	return 0;
}