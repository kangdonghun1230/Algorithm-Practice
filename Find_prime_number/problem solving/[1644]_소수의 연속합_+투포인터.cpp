/*
	Date: 2022/03/09
	Brief:
	two pointer example + sieve of eratosthenes
	Reference:
	https://cocoon1787.tistory.com/357
*/
#include <iostream>
#include <cmath>
#define MAX 4000001

using namespace std;

int primeNumber[MAX];
int number[MAX];
int cnt = 0;

void setPrime() {
	int i, j;
	
	for (i = 2; i <= sqrt(MAX); i++) {
		if (number[i] == 1)
			continue;
		for (j = i + i; j <= MAX; j += i) {
			number[j] = 1;
		}
	}

	for (i = 2; i < MAX; i++) {
		if (number[i] == 0) {
			primeNumber[cnt++] = i;
		}
	}

	return;
}

int main() {
	int n;
	cin.tie(NULL);

	cin >> n;

	setPrime();

	int res = 0, left = 0, right = 0;
	int sum = primeNumber[0];

	while (left <= right && right < cnt) {
		if (sum > n) {
			sum -= primeNumber[left++];
		}
		else if (sum < n) {
			sum += primeNumber[++right];
		}
		else {
			res++;
			sum -= primeNumber[left++]; // 다음 칸으로 넘어가서 다시 탐색하자.
		}
	}

	cout << res << "\n";

	return 0;
}