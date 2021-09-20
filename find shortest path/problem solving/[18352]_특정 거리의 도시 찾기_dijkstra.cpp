#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#define MAX 300001
#define INF 1000000

using namespace std;

vector<pair<int, int>> a[MAX];
int d[MAX];

void dijkstra(int start) {
	// distance, node
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;

		pq.pop();

		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].second;
			int next_distance = a[cur][i].first;

			if (distance + next_distance < d[next]) {
				d[next] = distance + next_distance;
				pq.push({ -d[next], next });
			}
		}
	}
	return;
}

int main() {
	int n, m, k, x;
	scanf("%d %d %d %d", &n, &m, &k, &x);
	fill(d, d + MAX, INF);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back({ 1, y });
	}
	// 시작 노드의 자체 거리는 0
	d[x] = 0;
	dijkstra(x);

	bool exist = false;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			printf("%d\n", i);
			exist = true;
		}
	}

	if (!exist) {
		printf("-1\n");
	}

	return 0;
}