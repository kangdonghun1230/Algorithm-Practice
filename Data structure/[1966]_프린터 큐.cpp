/*
	Date: 2022/03/13
	Brief:
	simple implementation with queue and priority queue
	Reference:
	https://artiper.tistory.com/72
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t;
	int i;
	cin.tie(NULL);
	cin >> t;

	while (t--) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;

		priority_queue<int> pq;
		queue<pair<int, int>> q; // index, priority
	
		for (i = 0; i < n; i++) {
			int priority;
			cin >> priority;
			q.push(pair<int, int>(i, priority));
			pq.push(priority);
		}

		while (!q.empty()) {
			int idx = q.front().first;
			int priority = q.front().second;
			q.pop();

			if (pq.top() == priority) {
				pq.pop();
				cnt++;
				if (m == idx) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push({ idx, priority });
			}
		}
	}

	return 0;
}