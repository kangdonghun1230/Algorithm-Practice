/*
	Date: 2022/03/30
	Brief:
	math + implementation
	Reference:
	수학 공식을 떠올리면 쉽게 푼다.
*/
#include <iostream>

using namespace std;

// sum = start * L + L(L-1)/2
// start * L = sum - L(L-1)/2
// start = (sum - L(L-1)/2=(1 ~ L-1 합))L

int main() {
	int N, L;
	bool found = false;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (L; L <= 100; L++) {
		int constant = L * (L - 1) / 2;
		int start = (N - constant) / L;

		// when start is int and start is positive number
		if ((N - constant) % L == 0 && start >= 0) {
			for (int i = 0; i < L; i++) {
				cout << start + i << " ";
			}
			found = true;
			cout << "\n";
			break;
		}
	}
	if (!found) {
		cout << "-1\n";
	}

	return 0;
}