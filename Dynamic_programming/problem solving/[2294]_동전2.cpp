#include <iostream>
#include <set>
#include <queue>

#define MAX 10001

using namespace std;

// n: ������ ���� ��, k: ��ǥ �ݾ�
int n, k;

// index: �������� ���� �� �ִ� �ݾ�, value: �ݾ��� ����� ���� �ּ� ���� ��
int d[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	// set���� �ߺ� ������ �ɷ�����.
	set<int> coinSet;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		int coinValue;
		cin >> coinValue;

		coinSet.insert(coinValue);
		// ���� �ϳ��� ���� �� �ִ� �ݾ׺��� ǥ���Ѵ�.
		if (coinValue < MAX) {
			d[coinValue] = 1;
			q.push(coinValue);
		}
	}


	while (!q.empty()) {
		int currentValue = q.front();
		q.pop();
		
		// ���� �ݾ� ��ü�� ��ǥġ�� ������ �ǳʶ��.
		if (currentValue > k)
			continue;

		for (auto it = coinSet.begin(); it != coinSet.end(); it++) {
			int coinValue = *it;

			if (currentValue + coinValue > k)
				continue;

			if (d[currentValue + coinValue] == 0) {
				d[currentValue + coinValue] = d[currentValue] + 1;
				// �ּڰ��� �����ϴ� ���� queue�� push�Ѵ�.
				q.push(currentValue + coinValue);
			}
			else if (d[currentValue + coinValue] <= d[currentValue] + 1) {
				continue;
			}
			else {
				d[currentValue + coinValue] = d[currentValue] + 1;
				// �ּڰ��� �����ϴ� ���� queue�� push�Ѵ�.
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