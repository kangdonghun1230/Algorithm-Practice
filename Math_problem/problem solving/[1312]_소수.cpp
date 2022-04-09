/*
	Date: 2022/04/09
	Brief:

	Reference:
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long a, b;
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> n;

	int res;

	int num = a;
	//cout << num /b << " " << num % b << "\n";
	num = a % b;
	while (n--) {
		num *= 10;
		//cout << num / b << " " << num % b << "\n";
		res = num / b;
		num %= b;
	}
	// n번째 소수점은 n번째 나눗셈 연산에서 몫의 결과이다.
	cout << res << "\n";

	return 0;
}