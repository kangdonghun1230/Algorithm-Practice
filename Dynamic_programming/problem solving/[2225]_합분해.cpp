#include <iostream>
#include <algorithm>
#define MAX 201
#define MOD 1000000000

using namespace std;

// 1����: ��, 2����: n���� ���� ����� ����� ��
int arr[MAX][MAX];
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		arr[i][1] = 1;
	}

	// i�� ������� �ϴ� ��
	for (int i = 0; i <= n; i++) {
	// r�� ���� ���� ��
		for (int r = 2; r <= k; r++) {
	// j�� 0 ~ i ������ ��
			for (int j = 0; j <= i; j++) {
				// i�� r���� ���� ����� ��� = i-j�� r-1 ���� ���� ����� + j ���ϱ�
				arr[i][r] += arr[i - j][r - 1];
				arr[i][r] %= MOD; // modulo ����
			}
		}
	}

	// n�̶�� ����, k������ ���� �̿��� ����� ����� ��
	cout << arr[n][k] % MOD;

	return 0;
}