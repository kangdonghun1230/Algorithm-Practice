/*
	Date: 2022/02/25
	Brief:
	MST (Minimum Spanning Tree) example problem
	Reference:
	https://blackon29.tistory.com/44
	https://github.com/rkdehdgns1230/Algorithm-Practice/blob/main/graph%20searching%20method/kruskalAlgorithm.cpp
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 10001

using namespace std;

bool visited[MAX];
long long res = 0;
vector<pair<int, int>> edge[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void prim(int v) {
	visited[v] = true;

	for (auto it : edge[v]) {
		if (!visited[it.second]) {
			pq.push({ it.first, it.second });
		}
	}

	while (!pq.empty()) {
		pair<int, int> w = pq.top();
		pq.pop();

		if (!visited[w.second]) {
			res += w.first;
			prim(w.second);
			return;
		}
	}
}

int main() {
	int v, e;
	int i;
	int x, y, z;
	cin.tie(NULL);
	cin >> v >> e;

	for (i = 0; i < e; i++) {
		cin >> x >> y >> z;
		edge[x].push_back({ z, y });
		edge[y].push_back({ z, x });
	}

	prim(1);

	cout << res << "\n";

	return 0;
}