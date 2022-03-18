#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

// edge data
vector<pair<int, int>> a[7];
// shortest path data
int d[7];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq; // heap structure
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int cur = pq.top().first; // shortest path's index in heap
		// ª�� ���̰� ���� ���� ����� �� �ֵ��� ������ ���·� ��������!
		int distance = -pq.top().second;
		pq.pop();

		// �̹� shortest path�� �ƴ� ��� skip
		if (d[cur] < distance) continue;

		// ���õ� ����� ���� ��带 �̿��Ͽ� �ּ� �Ÿ��� �����ϴ� for loop
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first;
			int next_distance = a[cur][i].second;
			next_distance += distance;

			if (d[next] > next_distance) {
				d[next] = next_distance;
				// same with pq.push(make_pair(next, -next_distance));
				pq.push(pair<int, int>(next, -next_distance));
			}
		}
	}
}

int main() {
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	for (int i = 1; i <= number; i++) {
		cout << d[i] << " ";
	}cout << endl;

	return 0;
}