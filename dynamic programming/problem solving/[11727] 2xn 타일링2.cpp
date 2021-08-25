#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int d[1001];

int dp(int x) {
	if (x == 0) 
		return 0;
	else if (d[x] != 0) 
		return d[x];
	else 
		return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
}

int main() {
	int n;
	d[1] = 1;
	d[2] = 3;

	scanf("%d", &n);

	printf("%d\n", dp(n));

	return 0;
}

/*
앞의 문제와 동일하게 타일의 종류에 따라 발생할 수 있는
경우의 수를 고려한 후 이를 바탕으로 점화식을 세우면
쉽게 해결할 수 있는 문제이다.

처음에는 풀기 어려웠으나, 몇번 접하다 보니 쉽게 풀이 가능하다.
*/