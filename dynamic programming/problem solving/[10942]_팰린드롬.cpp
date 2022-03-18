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
	s ~ e 범위의 수가 펠린드롬 수이기 위해서는 s+1 ~ e-1 범위의 수도
	펠린드롬 수 이어야 한다.

	- 즉, 아래의 조건을 만족해야 한다.
	arr[s] == arr[e] && palindrom[s+1][e-1] == true.

	그런데, length = 2 인 경우 위의 조건으로 모든 팰린드롬 수를 찾아내는게 불가능하다.
	왜냐하면 s+1 e-1 에 대해서 확인하는 경우 무조건 false로 뜨기 때문이다. (길이가 2인
	경우는 엇갈리니가 false로 초기화 되어있음.)

	이 말에 대한 자세한 reference는 아래의 링크를 참조하면 좋을 것 같다.
	https://4z7l.github.io/2021/04/07/algorithms-boj-10942.html

*/