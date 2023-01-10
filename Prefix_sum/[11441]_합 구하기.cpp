#include <iostream>
#define MAX 100001

using namespace std;

int prefixSum[MAX];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		// 바로 누적합을 계산한다.
		prefixSum[i] = prefixSum[i - 1] + num;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int start, end;

		cin >> start >> end;

		cout << prefixSum[end] - prefixSum[start - 1] << "\n";
	}

	return 0;
}