/*
	Date: 2022/02/14
	Brief:
	dynamic programming maybe(x)
	-> problem which has to solve with graph searching method (like BFS or DFS)
	because there is three way to go to the next step.
	Reference:
*/
#include <iostream>
#include <queue>
#define MAX 100001
#define INF 99999999

using namespace std;

int n, m;
int d[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		d[i] = INF;
	}
}

bool inTheRange(int x) {
	if (x < 0 || x >= MAX) return false;
	else return true;
}

void BFS() {
	// first initialize whole elements with INF(99999999)
	init();

	queue<int> q;
	q.push(n);
	d[n] = 0;

	while (!q.empty()) {
		int cur = q.front();

		//pop from the queue
		q.pop();

		// push to queue, when the shortest distance is updated
		if (inTheRange(cur + 1) && d[cur] + 1 < d[cur + 1]) {
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
		if (inTheRange(cur * 2) && d[cur] < d[cur * 2]) {
			d[cur * 2] = d[cur];
			q.push(cur * 2);
		}
		if (inTheRange(cur - 1) && d[cur] + 1 < d[cur - 1]) {
			d[cur - 1] = d[cur] + 1;
			q.push(cur - 1);
		}
	}

	return;
}

int main() {
	cin.tie(NULL);
	cin >> n >> m;

	BFS();

	cout << d[m] << "\n";

	return 0;
}