/*
	Date: 2022/04/01
	Brief:
	math? sort
	Reference:
	just sort array and calculate the multiple of first and last number
*/
#include <iostream>
#define MAX 1001

using namespace std;

int main() {
	int n, m;
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int minPackage = MAX, minOne = MAX;

	for (i = 0; i < m; i++) {
		int package, one;
		cin >> package >> one;

		minPackage = (minPackage > package) ? package : minPackage;
		minOne = (minOne > one) ? one : minOne;
	}

	minPackage = (minPackage > (6 * minOne)) ? (6 * minOne) : minPackage;

	int totalCost = (n / 6) * minPackage;
	totalCost += (n % 6) * minOne;

	totalCost = (totalCost > ((n / 6 + 1) * minPackage)) ? ((n / 6 + 1) * minPackage) : totalCost;

	cout << totalCost << "\n";

	return 0;
}