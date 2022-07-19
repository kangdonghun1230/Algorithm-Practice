/*
	Date: 2022/07/18
	Brief:
	Dijkstra
	Reference:
*/
#include <iostream>
#include <vector>
#include <queue>

#define MAX 50001
#define MAX_DIS 50000001

using namespace std;

int d[MAX];
int n, m;

vector<pair<int, int>> v[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, start });

	for (int i = 1; i <= n; i++) {
		d[i] = MAX_DIS;
	}
	d[start] = 0;
	
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();

		// 이미 최소 경로가 아닌 경우 skip
		if (d[cur] < dis)
			continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dis = v[cur][i].second + dis;

			if (d[next] > next_dis) {
				d[next] = next_dis;
				pq.push({ -next_dis, next });
			}
		}
	}

	return;
}

int main() {
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, distance;

		cin >> start >> end >> distance;

		v[start].push_back({ end, distance });
		v[end].push_back({ start, distance });
	}

	dijkstra(1);

	cout << d[n] << endl;

	return 0;
}