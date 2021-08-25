#include <iostream>

using namespace std;

// initialize array for memoization

int d[100];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x];

	return d[x] = dp(x - 1) + dp(x - 2);
}

int main() {
	d[1] = 1, d[2] = 1;

	printf("%d\n", dp(30));

	return 0;
}