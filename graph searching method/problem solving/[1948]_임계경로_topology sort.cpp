#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001

using namespace std;

class Edge {
public:
	int end;
	int time;
	Edge(int end, int time) {
		this->end = end;
		this->time = time;
	}
};

vector<Edge> a[MAX];
vector<Edge> b[MAX];
int n, start, finish;
// 진입차수, 각 정점의 최장경로, check array
int inDegree[MAX], result[MAX], c[MAX];

void topologySort() {
	queue<int> q;

	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		// 인접한 노드를 검사한다.
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].end, a[x][i].time);
			result[y.end] = max(result[y.end], result[x] + y.time);

			if (--inDegree[y.end] == 0) {
				q.push(y.end);
			}
		}
	}

	int cnt = 0;
	q.push(finish);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < b[x].size(); i++) {
			Edge y = Edge(b[x][i].end, b[x][i].time);

			if (result[y.end] == result[x] - y.time) {
				cnt++;
				if (c[y.end] == 0) {
					q.push(y.end);
					c[y.end] = 1;
				}
			}
		}
	}
	printf("%d\n%d\n", result[finish], cnt);
}

int main() {
	int m;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int sta, end, time;
		scanf("%d %d %d", &sta, &end, &time);

		a[sta].push_back(Edge(end, time));
		b[end].push_back(Edge(sta, time));
		inDegree[end]++;
	}
	scanf("%d %d", &start, &finish);

	topologySort();

	return 0;
}