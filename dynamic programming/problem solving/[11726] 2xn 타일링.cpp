#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int d[1001];

int dp(int x) {
	if (x == 0) return 0;
	else if (d[x] != 0)
		return d[x];
	else
		return d[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}

int main() {
	int n;
	scanf("%d", &n);
	d[1] = 1; d[2] = 2;
	
	printf("%d\n", dp(n));


	return 0;
}

/*
2 x 1, 1 x 2 타일만을 갖고 2 x n 타일을 채우는 경우의 수를 구하는 문제입니다.

총 두 가지의 경우에 대해서 생각을 해야하는데 현재 타일에서 1칸을 덜 채우는 경우에
1 x 2 타일을 추가하는 경우와 현재 타일에서 2칸을 덜 채우는 경우에 2 x 1 타일을 두개
쌓는 경우 총 2가지 경우가 발생하게 됩니다.

따라서 2 x n을 채우는 경우의 수 = 2 x n-1 채우는 경우의 수 + 2 x n-2 채우는 경우의 수
위와 같이 구하면 쉽게 문제를 해결할 수 있게 됩니다.
*/