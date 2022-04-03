/*
	Date: 2022/04/03
	Brief:
	math
	Reference:

*/
#include <iostream>
#define MAX 10000001

using namespace std;

bool isPrimeNum[MAX];

void sieveOfEratothenes(int n) {
	int i, j;

	isPrimeNum[1] = true;
	isPrimeNum[2] = false;
	
	for (i = 2; i <= n; i++) {
		if (isPrimeNum[i]) {
			continue;
		}
		for (j = i * 2; j <= n; j += i) {
			isPrimeNum[j] = true;
		}
	}

	return;
}

int main() {
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	sieveOfEratothenes(n);

	while (n != 1) {
		int minPrime = 0;

		for (int i = 2; i <= n; i++) {
			if (!isPrimeNum[i] && n % i == 0) {
				minPrime = i;
				break;
			}
		}
		cout << minPrime << "\n";
		n /= minPrime;
	}

	return 0;
}