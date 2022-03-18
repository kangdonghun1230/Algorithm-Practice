#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	while (1) {
		int s1, s2, s3;
		cin >> s1 >> s2 >> s3;

		if (s1 == 0 && s2 == 0 && s3 == 0) break;

		int diag = max(s1, s2);
		diag = max(diag, s3);

		if (diag == s1 && pow(s1, 2) == pow(s2, 2) + pow(s3, 2)) {
			cout << "right\n";
		}
		else if (diag == s2 && pow(s2, 2) == pow(s1, 2) + pow(s3, 2)) {
			cout << "right\n";
		}
		else if(diag == s3 && pow(s3, 2) == pow(s2, 2) + pow(s1, 2)) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}

	}

	return 0;
}