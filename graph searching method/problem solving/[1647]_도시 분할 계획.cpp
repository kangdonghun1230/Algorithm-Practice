/*
	Date: 2022/03/04
	Brief:
	MST with Kruskal method
	Reference:

*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int parent[MAX];

class Edge {
public:
	int start, end;
	int dis;
	Edge(int start, int end, int dis) {
		this->start = start;
		this->end = end;
		this->dis = dis;
	}

	bool operator<(Edge& it){
		return this->dis < it.dis;
	}
};

int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool checkParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x == y) return true;
	else return false;
}

int main() {
	int n, m, i;
	vector<Edge> e;
	cin.tie(NULL);

	cin >> n >> m;
	int remain = n - 1;

	for (i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		e.push_back(Edge(a, b, c));
	}

	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}
	// sort by distance of Edges
	sort(e.begin(), e.end());

	int res = 0;

	for (i = 0; i < e.size(); i++) {
		// check if the two node's parents are same or not.
		if (!checkParent(e[i].start, e[i].end)) {
			remain--;
			// last link is not connected for constructing two villages.
			if (remain != 0)
				res += e[i].dis;
			// union two nodes parent.
			unionParent(e[i].start, e[i].end);
			
		}
	}

	cout << res << "\n";
	return 0;
}