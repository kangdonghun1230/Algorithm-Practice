#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define MAX 2187
//#define MAX (int)pow(3, 7)

using namespace std;

int paper[MAX][MAX];

string solve(int n, int i, int j) {
	if (n == 1) {
		return to_string(paper[i][j] + 1);
	}

	string tmp[9];
	tmp[0] = solve(n / 3, i, j);
	tmp[1] = solve(n / 3, i, j + n / 3);
	tmp[2] = solve(n / 3, i, j + (2 * n) / 3);
	tmp[3] = solve(n / 3, i + n / 3, j);
	tmp[4] = solve(n / 3, i + n / 3, j + n / 3);
	tmp[5] = solve(n / 3, i + n / 3, j + (2 * n) / 3);
	tmp[6] = solve(n / 3, i + (2 * n) / 3, j);
	tmp[7] = solve(n / 3, i + (2 * n) / 3, j + n / 3);
	tmp[8] = solve(n / 3, i + (2 * n) / 3, j + (2 * n) / 3);

	bool same = true;
	for (int i = 0; i < 9; i++) {
		if (tmp[i] != tmp[0]) same = false;
	}

	// 9 elements are same
	if (same && tmp[0].size() == 1) {
		return tmp[0];
	}
	// not same
	else {
		string result = "(";
		for (int i = 0; i < 9; i++) {
			result += tmp[i];
		}
		result += ')';

		return result;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	
	string result = solve(n, 0, 0);

	int cnt[3] = { 0, };
	for (int i = 0; i < result.size(); i++) {
		if (result[i] == '0') cnt[0]++;
		else if (result[i] == '1') cnt[1]++;
		else if (result[i] == '2') cnt[2]++;
	}
	cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];

	return 0;
}

/*
000 000 000
000 000 000
001 001 001

000 000 000
000 000 000
001 001 001

000 000 000
000 000 000
001 001 001
위 같은 경우때문에 모두 다 같은 모양의 종이일지라도
종이의 길이가 1이 아닌 경우에 대해서 따로 처리해야 한다.
*/