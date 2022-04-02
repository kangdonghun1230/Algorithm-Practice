/*
	Date: 2022/04/02
	Brief:
	math
	Reference:
	problem solving code for 1934 BOJ
*/
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lca(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int t;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << '\n';
	}

	return 0;
}