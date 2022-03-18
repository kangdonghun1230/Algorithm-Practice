#include<iostream>
#define MAX 10001

using namespace std;

int a[MAX];

int getSelfNumber(int x) {
	int result = x;
	while (1) {
		result += (x % 10);
		if (x < 10) break;
		x /= 10;
	}
	return result;
}

void selfNumber() {
	a[0] = 1;
	a[1] = 0;
	for (int i = 1; i < MAX; i++) {
		int x = getSelfNumber(i);
		// x is a self number already
		if (a[x] == 1) continue;
		a[x] = 1;
	}

	return;
}

int main() {
	selfNumber();

	for (int i = 1; i < MAX; i++) {
		if (a[i] == 0) printf("%d\n", i);
	}

	return 0;
}