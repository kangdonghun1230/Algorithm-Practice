#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 101

using namespace std;

string c[MAX][MAX];

// long long type을 넘어서는 결과를 저장하고 출력해야 하기 때문에
// string으로 변환하여 결과를 계산하는 함수가 필요합니다.
string strNumAdd(string a, string b) {
	long long sum = 0;
	string result;

	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		// 다시 string type으로 만들어 push back
		result.push_back((sum % 10) + '0');
		// 다음 자리수로 넘긴다.
		sum /= 10;
	}
	// 역순으로 넣었기 때문에 뒤집어준다.
	reverse(result.begin(), result.end());
	return result;
}

// 파스칼의 삼각형 기법을 활용하여 combination을 계산해준다.
string combination(int n, int m) {
	if (m == 0 || n == m) return "1";
	else if (c[n][m] != "") return c[n][m];
	else {
		// 하나를 빼고 뽑은 경우 + 하나를 포함하고 나머지를 뽑은 경우
		return c[n][m] = strNumAdd(combination(n - 1, m - 1), combination(n - 1, m));
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		c[i][0] = "1";
		c[i][i] = "1";
	}

	cout << combination(n, m) << endl;

	return 0;
}