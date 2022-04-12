/*
	Date: 2022/04/12
	Brief:
	math problem + implementation
	Reference:
*/
#include <iostream>
#include <string>

using namespace std;


int main() {
	string l, r;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> r;

	if (l.length() != r.length()) {
		cout << "0\n";
		return 0;
	}

	int len = l.length();
	int cnt = 0;

	for (int i = 0; i < len; i++) {
		if (l[i] == r[i] && l[i] == '8')
			cnt++;
		else if (l[i] == r[i])
			continue;
		else
			break;
	}

	cout << cnt << "\n";

	return 0;
}
/*
두 수의 자리수가 다르면 -> 0
두 수의 자리수가 같으면 -> 
1. 가장 큰 자리수부터 탐색 8의 개수가 몇인지가 답.
2. 8이 아닌 다른 수로 같은 경우에는 다음 자리수로 탑색
3. 해당 자리수에서 숫자가 다른 경우 탐색 종료 -> 더 이상 8이 등장할 필요 없음
*/