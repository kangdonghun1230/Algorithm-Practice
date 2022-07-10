/*
	Date: 2022/07/10
	Brief:
	sieve of eratosthenes
	Reference:
*/
#include <iostream>
#include <cmath>

#define MAX 100001

using namespace std;

int a, b;
int arr[MAX]; // index가 소수인 경우 0의 값을 갖는다.

// sieve of eratosthenes를 이용해 소수를 구한다.
void sieveOfEratosthenes(int x) {
	arr[0] = 1, arr[1] = 1, arr[2] = 0;

	for (int i = 2; i <= sqrt(x); i++) {
		if (arr[i] == 1)
			continue;

		// i(소수)의 배수는 모두 소수가 아니다.
		for (int j = 2 * i; j <= x; j += i) {
			if (arr[j] == 1)
				continue;
			arr[j] = 1;
		}
	}

	return;
}

// 소인수 분해 (prime factorization)
int primeFactorization(int num) {
	int cnt = 0;

	for (int i = 2; i <= num; i++) {
		if (arr[i] == 1)
			continue;
		
		while (num % i == 0) {
			num /= i;
			cnt++;
		}

		if (num == 1) break;
	}
	return cnt;
}

int main() {
	int i, res = 0;

	cin.tie(NULL);
	cin >> a >> b;

	sieveOfEratosthenes(b);

	for (i = a; i <= b; i++) {
		int tmp = primeFactorization(i);

		// 소인수분해 결과 인수의 개수가 소수인 경우 ++
		if (arr[tmp] == 0) {
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}