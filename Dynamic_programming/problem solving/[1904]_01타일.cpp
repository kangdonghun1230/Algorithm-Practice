/*
	Date: 2022/04/16
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#define MAX 1000001

using namespace std;

int dp[MAX];

int main() {
	int n;
	int i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		// normalization with 15476
		dp[i] %= 15476;
	}

	cout << dp[n] << "\n";


	return 0;
}

/*
n = 1: 1 1����
n = 2: 00, 11 2����
n = 3: 100, 001, 111 3����
n = 4: 1001, 1100, 0011, 0000, 1111 5����
n = 5: 11001, 10011, 11100, 00111, 10000, 00100, 00001, 11111 8����
n = 6: 100100, 110000, 001100, 000000, 111100,
       110011, 100111, 111001, 001111, 100001, 001001, 000011, 111111

��������� ���� n������ ��������
n-1�� ��쿡 1�� concatenation�ϴ� ����� �� + n-2�� ��쿡 00�� concatenation�ϴ� ����� ��
�� ������ ������ ������ �����ϴ�.
*/