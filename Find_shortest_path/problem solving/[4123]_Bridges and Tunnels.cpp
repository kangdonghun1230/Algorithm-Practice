#include <iostream>
#include <vector>
#include <queue>
#define MAX 4001
#define INF 9987654321
#define endl "\n"

using namespace std;
int n, m, p;
// outside time, total time
pair<long long, long long> d[MAX];
// destination, distance, 0/1: inside, outside
vector<pair<int, pair<long long, int>>> v[MAX];

void dijkstra(int x) {
	// outside time, total time, site
	priority_queue<pair<long long, pair<long long, int>>, vector<pair<long long, pair<long long, int>>>, greater<pair<long long, pair<long long, int>>>> pq;

	pq.push({0, {0, x}});

	for (int i = 0; i < n; i++) {
		if (i == x) {
			d[i] = { 0, 0 };
			continue;
		}
		d[i] = { INF, INF };
	}

	while (!pq.empty()) {
		// current site
		int site = pq.top().second.second;
		long long total_time = pq.top().second.first;
		long long outside_time = pq.top().first;
		pq.pop();

		for (int i = 0; i < v[site].size(); i++) {
			int next_site = v[site][i].first;
			long long next_total_time = total_time + v[site][i].second.first;
			int isInOrOut = v[site][i].second.second;
			long long next_outside_time = outside_time;
			// inside path
			if (isInOrOut == 0) {
				// outside time 그대로
			}
			// outside path
			else {
				next_outside_time += v[site][i].second.first;
			}
			// 이미 갱신 불가능한 경우 스킵
			if (next_outside_time > d[next_site].first)
				continue;

			// 외부 노출 시간 갱신 가능한 경우
			if (next_outside_time < d[next_site].first) {
				d[next_site].first = next_outside_time;
				d[next_site].second = next_total_time;
				pq.push({ next_outside_time, {next_total_time, next_site} });
			}
			// 외부 노출 시간은 같으나 총 소모 시간이 적은 경우
			else if (next_outside_time == d[next_site].first && next_total_time < d[next_site].second) {
				d[next_site].second = next_total_time;
				pq.push({ next_outside_time, {next_total_time, next_site} });
			}
			else {
				continue;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> p;

	for (int i = 0; i < m; i++) {
		int start, end;
		long long distance;
		char inOut;

		cin >> start >> end >> distance >> inOut;

		int inOutNum = (inOut == 'I') ? 0 : 1;

		v[start].push_back({ end, {distance, inOutNum} });
		v[end].push_back({ start, {distance, inOutNum} });
	}

	for (int i = 0; i < p; i++) {
		int start, end;
		cin >> start >> end;
		dijkstra(start);
		if (d[end].first == INF || d[end].second == INF) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << d[end].first << " " << d[end].second << endl;
		}
	}

	return 0;
}