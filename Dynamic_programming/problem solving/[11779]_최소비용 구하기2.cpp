#include <iostream>
#include <queue>
#include <vector>

#define MAX_V 1001
#define MAX 1000000001

using namespace std;

vector<pair<int, int>> v[MAX_V];

int n, m;
int d[MAX_V][2];

// 최단 거리 배열을 최댓값으로 모두 초기화
void init() {
	for (int i = 1; i <= n; i++) {
		d[i][0] = MAX;
	}
	return;
}

void dijkstra(int start) {
	//distance, end
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, start });
	init();
	d[start][0] = 0;
	d[start][1] = start; // 이전에 방문한 노드는 자기 자신 (출발점)

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();

		// 사전 차단
		if (dis > d[cur][0])
			continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dis = dis + v[cur][i].second;

			// 방문했거나, 최단거리 갱신 안되면 건너띄자.
			if (next_dis >= d[next][0])
				continue;

			// 최단거리 갱신될 때, 최단 거리와 이전 방문 노드를 바꿔준다.
			d[next][0] = next_dis;
			d[next][1] = cur;

			pq.push({ -next_dis, next });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, dis;
		cin >> start >> end >> dis;

		v[start].push_back({ end, dis });
	}
	int departure, destination;

	cin >> departure >> destination;

	dijkstra(departure);

	cout << d[destination][0] << "\n";

	vector<int> path;
	int cur = destination;

	while (1) {
		if (d[cur][1] == cur) {
			path.push_back(cur);
			break;
		}
		path.push_back(cur);
		cur = d[cur][1];
	}

	cout << path.size() << "\n";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}

	
	return 0;
}