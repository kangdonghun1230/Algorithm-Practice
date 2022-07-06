/*
	Date: 2022/07/07
	Brief:
	Brute-Force
	Reference:
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[21];
int n, s;
int res_cnt;
int total;
// 계속해서 경우의 수를 이진 트리로 증폭시켜나가는 방식으로 구현
// 시간 복잡도 보장되기 때문에, 단순 브루트포스로 해결
void sumFunc(int cnt, int sum) {
	if (cnt == n) {
		if (sum == s) {
			res_cnt++;
		}

		return;
	}
	// 현재 element 포함
	sumFunc(cnt + 1, sum + arr[cnt]);
	// 현재 element 미포함
	sumFunc(cnt + 1, sum);
}

int main() {
	int i, j;

	cin.tie(NULL);

	cin >> n >> s;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sumFunc(0, 0);

	// 전부 선택하지 않은 경우 0이 등장하기 때문이다.
	if (s == 0) res_cnt--;

	cout << res_cnt << "\n";

	return 0;
}

/*
대충 최대 경우의 수를 따져보면 100만회정도 이므로
1초 가까이 소모된다. 근데, 시간 제약이 2초이므로 
모든 부분수열을 체크하면서 -> S가 합이 되는 경우를 찾으면 된다.
*/
