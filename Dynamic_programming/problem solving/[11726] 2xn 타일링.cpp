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
2 x 1, 1 x 2 Ÿ�ϸ��� ���� 2 x n Ÿ���� ä��� ����� ���� ���ϴ� �����Դϴ�.

�� �� ������ ��쿡 ���ؼ� ������ �ؾ��ϴµ� ���� Ÿ�Ͽ��� 1ĭ�� �� ä��� ��쿡
1 x 2 Ÿ���� �߰��ϴ� ���� ���� Ÿ�Ͽ��� 2ĭ�� �� ä��� ��쿡 2 x 1 Ÿ���� �ΰ�
�״� ��� �� 2���� ��찡 �߻��ϰ� �˴ϴ�.

���� 2 x n�� ä��� ����� �� = 2 x n-1 ä��� ����� �� + 2 x n-2 ä��� ����� ��
���� ���� ���ϸ� ���� ������ �ذ��� �� �ְ� �˴ϴ�.
*/