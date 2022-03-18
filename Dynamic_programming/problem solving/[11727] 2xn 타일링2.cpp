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
���� ������ �����ϰ� Ÿ���� ������ ���� �߻��� �� �ִ�
����� ���� ����� �� �̸� �������� ��ȭ���� �����
���� �ذ��� �� �ִ� �����̴�.

ó������ Ǯ�� ���������, ��� ���ϴ� ���� ���� Ǯ�� �����ϴ�.
*/