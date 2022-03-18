/*
	Date: 2022/02/25
	Brief:
	MST (Minimum Spanning Tree) example problem
	Reference:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;

class Edge {
public:
	int node[2];
	int dis;

	Edge(int a, int b, int dis) {
		this->node[0] = a;
		this->node[1] = b;
		this->dis = dis;
	}

	bool operator< (Edge& edge) {
		return this->dis < edge.dis;
	}
};

int getParent(int parent[], int a) {
	if (parent[a] == a) return a;
	else return parent[a] = getParent(parent, parent[a]);
}

void unionParent(int parent[], int a, int b) {
	// get the parents of a and b
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool checkParent(int parent[], int a, int b) {
	// get the parents of a and b
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return true;
	else return false;
}

int main() {
	int V, E;
	int i;
	int parent[MAX];
	vector<Edge> v;
	
	scanf("%d %d", &V, &E);

	for (i = 0; i < E; i++) {
		int x, y, z;

		scanf("%d %d %d", &x, &y, &z);
		v.push_back(Edge(x, y, z));
	}

	for (i = 1; i <= V; i++) {
		parent[i] = i;
	}
	// sorting whole elements in vector v.
	sort(v.begin(), v.end());

	long long sum = 0;

	// union edges from the shortest cost.
	for (i = 0; i < v.size(); i++) {
		// check if two nodes are connected
		if (!checkParent(parent, v[i].node[0], v[i].node[1])) {
			sum += v[i].dis;
			unionParent(parent, v[i].node[0], v[i].node[1]);
		}
	}

	printf("%lld\n", sum);

	return 0;
}