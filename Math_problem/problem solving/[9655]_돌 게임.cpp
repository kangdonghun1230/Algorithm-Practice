#include <iostream>

using namespace std;

int main() {
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n % 2 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}
	return 0;
}