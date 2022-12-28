#include <iostream>
#include <set>
#include <queue>

#define MAX 10001

using namespace std;

// n: 동전의 가지 수, k: 목표 금액
int n, k;

// index: 동전으로 만들 수 있는 금액, value: 금액을 만들기 위한 최소 동전 수
int d[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	// set으로 중복 동전을 걸러낸다.
	set<int> coinSet;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		int coinValue;
		cin >> coinValue;

		coinSet.insert(coinValue);
		// 동전 하나로 만들 수 있는 금액부터 표기한다.
		if (coinValue < MAX) {
			d[coinValue] = 1;
			q.push(coinValue);
		}
	}


	while (!q.empty()) {
		int currentValue = q.front();
		q.pop();
		
		// 현재 금액 자체가 목표치를 넘으면 건너띈다.
		if (currentValue > k)
			continue;

		for (auto it = coinSet.begin(); it != coinSet.end(); it++) {
			int coinValue = *it;

			if (currentValue + coinValue > k)
				continue;

			if (d[currentValue + coinValue] == 0) {
				d[currentValue + coinValue] = d[currentValue] + 1;
				// 최솟값을 갱신하는 경우는 queue에 push한다.
				q.push(currentValue + coinValue);
			}
			else if (d[currentValue + coinValue] <= d[currentValue] + 1) {
				continue;
			}
			else {
				d[currentValue + coinValue] = d[currentValue] + 1;
				// 최솟값을 갱신하는 경우는 queue에 push한다.
				q.push(currentValue + coinValue);
			}
		}
	}

	if (d[k])
		cout << d[k];
	else
		cout << -1;

	return 0;
}