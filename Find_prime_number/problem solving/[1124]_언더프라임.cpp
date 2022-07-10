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
int arr[MAX]; // index�� �Ҽ��� ��� 0�� ���� ���´�.

// sieve of eratosthenes�� �̿��� �Ҽ��� ���Ѵ�.
void sieveOfEratosthenes(int x) {
	arr[0] = 1, arr[1] = 1, arr[2] = 0;

	for (int i = 2; i <= sqrt(x); i++) {
		if (arr[i] == 1)
			continue;

		// i(�Ҽ�)�� ����� ��� �Ҽ��� �ƴϴ�.
		for (int j = 2 * i; j <= x; j += i) {
			if (arr[j] == 1)
				continue;
			arr[j] = 1;
		}
	}

	return;
}

// ���μ� ���� (prime factorization)
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

		// ���μ����� ��� �μ��� ������ �Ҽ��� ��� ++
		if (arr[tmp] == 0) {
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}