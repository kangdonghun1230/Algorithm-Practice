#include <iostream>
#define MAX 1000001

using namespace std;

int n, m;

long long moduloCnt[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	long long curCumulativeSum = 0;

	for (int i = 0; i < n; i++) {
		int curNum;
		cin >> curNum;

		curCumulativeSum += curNum;

		// 현재까지의 값의 누적합의 m에 대한 모듈러 연산을 적용하고
		// 나머지 값을 인덱스로 하는 배열의 값++
		moduloCnt[curCumulativeSum % m]++;
	}

	// 나머지가 0인 결과들은 0 ~ i까지의 구간 합의 경우도 포함이 됨을 의미한다.
	long long resCnt = moduloCnt[0];

	for (int i = 0; i < m; i++) {
		// n개가 나머지가 같다 = n(n-1)/2 개(=nC2)의 조합이 탄생함을 의미
		resCnt += (moduloCnt[i] * (moduloCnt[i] - 1)) / 2;
	}

	cout << resCnt;

	return 0;
}

/*
* 누적합의 계산은 (prefixSum[i] - prefixSum[j])로 계산한다.
* m으로 나누어 떨어지는 구간 i ~ j의 합은 (prefixSum[i] - prefixSum[j]) % m == 0
* 하나를 우변으로 넘기면 prefixSum[i] % m == prefixSum[j] % m이 된다.
* 따라서 우리는 누적합의 나머지 값에 주목하면 된다.
* 나머지가 같은 값끼리 구간합을 구하면 m에 대한 모듈러 연산 결과가 0일 것이다.
* 
* 우리는 같은 애들을 조합하는 경우의 수만 계산하면 된다.
*/