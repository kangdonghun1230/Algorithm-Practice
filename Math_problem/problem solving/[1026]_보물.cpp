/*
	Date: 2022/03/30
	Brief:
	math + implementation
	Reference:
	수학 공식을 떠올리면 쉽게 푼다.
*/
#include <iostream>
#include <algorithm>
#define MAX 51

using namespace std;

int main() {
	int A[MAX], B[MAX];
	int n;
	int i, j;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + n);

	int res = 0;

	for (i = 0; i < n; i++) {
		res += (A[i] * B[n - i - 1]);
	}

	cout << res << "\n";


	return 0;
}