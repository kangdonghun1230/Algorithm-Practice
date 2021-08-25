#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int d[31];

int dp(int x) {
	if (x == 0) return 1;
	else if (x == 1) return 0;
	else if (x == 2) return 3;
	else if (d[x] != 0) return d[x];
	
	int result = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * dp(x - i);
		}
	}

	return d[x] = result;
}

int main() {
	d[0] = 1; d[1] = 0; d[2] = 3;
	int n;
	scanf("%d", &n);

	printf("%d\n", dp(n));

	return 0;
}

/*
이전 문제들과는 다르게 짝수개일 때 2가지씩
추가적인 경우의 수가 생깁니다. (가운데 지르고 위아래 뒤집으니)
*/