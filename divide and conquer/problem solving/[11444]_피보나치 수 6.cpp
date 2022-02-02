/*
	Date: 2022/02/02
	Brief:
	Program for calculating Fibonacci numbers
	Reference:
	d'Ocagne's identity(도가뉴의 항등식)
	Fm+n = Fm-1Fn + FmFn+1 이라는 항등식이 성립한다고 한다. (피보나치 수열에 대해서)
	-> F2n = Fn-1Fn + FnFn+1, F2n-1 = FnFn + Fn-1Fn-1
	-> F2n = Fn(Fn-1 + Fn+1) = Fn(2Fn-1 + Fn) (by Fn = Fn-1 + Fn-2)
	https://ko.wikipedia.org/wiki/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98_%EC%88%98
	https://www.acmicpc.net/blog/view/28
*/

#include <iostream>
#include <map>

using namespace std;

const long long mod = 1000000007LL; // long long type value
// format: map<key, value> map1
map<long long, long long> d;

// fibonacci with d'Ocagne's identity
long long fibonacci(long long n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (d.count(n) > 0)
		return d[n];
	else {
		if (n % 2 == 1) {	// if n is odd number
			long long m = (n + 1) / 2;
			long long tmp1 = fibonacci(m);
			long long tmp2 = fibonacci(m - 1);
			// F2m-1 = FmFm + Fm-1Fm-1
			d[n] = (tmp1 * tmp1) + (tmp2 * tmp2);
			d[n] %= mod;

			return d[n];
		}
		else {	// if n is even number
			long long m = n / 2;
			long long tmp1 = fibonacci(m);
			long long tmp2 = fibonacci(m - 1);

			d[n] = (2LL * tmp2 + tmp1) * tmp1;
			d[n] %= mod;

			return d[n];
		}
	}
}

int main() {
	long long n;
	cin.tie(NULL);

	cin >> n;
	cout << fibonacci(n) << "\n";

	return 0;
}