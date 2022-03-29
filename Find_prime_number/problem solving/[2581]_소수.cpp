/*
	Date: 2022/03/29
	Brief:
	sieve of eratosthenes maybe
	Reference:
*/
#include <iostream>
#include <cmath>
#define MAX 10001

using namespace std;

// false: prime, true: not prime number
bool primeNumber[MAX];
int res = 0;
bool isPresent = false;

void sieveOfEratosthenes(int n) {
	int i, j;
	// 1 is not a prime number
	primeNumber[1] = true;
	primeNumber[2] = false;

	for (i = 2; i <= sqrt(n); i++) {
		if (primeNumber[i]) continue;
		for (j = 2 * i; j <= n; j += i) {
			// multiple of prime number is not a prime number.
			primeNumber[j] = true;
		}
	}

	return;
}

int calculateSum(int a, int b) {
	int min = MAX;
	for (int i = a; i <= b; i++) {
		if (!primeNumber[i]) {
			res += i;
			min = (min < i) ? min : i;
			isPresent = true;
		}
	}
	return min;
}

int main() {
	int m, n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	cin >> n;

	sieveOfEratosthenes(n);
	int min = calculateSum(m, n);

	if (isPresent)
		cout << res << "\n" << min << "\n";
	else
		cout << "-1\n";

	return 0;
}