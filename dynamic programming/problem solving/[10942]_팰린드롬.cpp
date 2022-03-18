/*
	Date: 2022/03/18
	Brief:
	dynamic programming example
	Reference:
	https://4z7l.github.io/2021/04/07/algorithms-boj-10942.html
*/
#include <iostream>
#define MAX 2001

using namespace std;

bool palindrom[MAX][MAX];

int arr[MAX];

int main() {
	int n, m;
	int i, j;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// initialization for dynamic programming
	for (i = 1; i <= n; i++) {
		palindrom[i][i] = true;
	}
	// length == 2 case
	for (i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1])
			palindrom[i][i + 1] = true;
	}
	// length >= 3 case
	for (i = n - 1; i >= 1; i--) {
		for (j = i + 1; j <= n; j++) {
			if (arr[i] == arr[j] && palindrom[i + 1][j - 1])
				palindrom[i][j] = true;
		}
	}

	cin >> m;

	for (i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		cout << palindrom[s][e] << "\n";
	}

	return 0;
}

/*
	s ~ e ������ ���� �縰��� ���̱� ���ؼ��� s+1 ~ e-1 ������ ����
	�縰��� �� �̾�� �Ѵ�.

	- ��, �Ʒ��� ������ �����ؾ� �Ѵ�.
	arr[s] == arr[e] && palindrom[s+1][e-1] == true.

	�׷���, length = 2 �� ��� ���� �������� ��� �Ӹ���� ���� ã�Ƴ��°� �Ұ����ϴ�.
	�ֳ��ϸ� s+1 e-1 �� ���ؼ� Ȯ���ϴ� ��� ������ false�� �߱� �����̴�. (���̰� 2��
	���� �������ϰ� false�� �ʱ�ȭ �Ǿ�����.)

	�� ���� ���� �ڼ��� reference�� �Ʒ��� ��ũ�� �����ϸ� ���� �� ����.
	https://4z7l.github.io/2021/04/07/algorithms-boj-10942.html

*/