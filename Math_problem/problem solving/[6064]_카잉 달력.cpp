/*
	Date: 2022/03/26
	Brief:
	math problem
	Reference:
	https://yhwan.tistory.com/17
	https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95
	https://ko.wikipedia.org/wiki/%EC%A4%91%EA%B5%AD%EC%9D%B8%EC%9D%98_%EB%82%98%EB%A8%B8%EC%A7%80_%EC%A0%95%EB%A6%AC
*/
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	// a must be bigger one
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

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int t;
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		int n, m, x, y;
		cin >> m >> n >> x >> y;

		if (x > m || y > n) {
			cout << "-1\n";
			continue;
		}

		int lastYear = lcm(m, n);

		// 두 수의 최소 공배수 구해서 해당 수까지 확인한 담에
		// 있었으면 출력하면 되고, 없으면 -1 출력하면 댄다.
		for (i = x; i <= lastYear; i += m) {
			int tmp = (i % n == 0) ? n : (i % n);

			if (tmp == y) {
				cout << i << "\n";
				break;
			}
		}

		// out of bound == couldn't find x, y
		if (i > lastYear)
			cout << "-1\n";
	}


	return 0;
}