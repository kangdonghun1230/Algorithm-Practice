/*
	Date: 2022/03/15
	Brief:

	Reference:
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAX 101

using namespace std;

int n;
int parent[MAX];
vector<pair<double, double>> coord;
vector<pair<double, pair<int, int>>> Edge;
double res = 0;

double calDistance(double x1, double y1, double x2, double y2) {
	double disX = (x1 - x2) * (x1 - x2);
	double disY = (y1 - y2) * (y1 - y2);

	return sqrt(disX + disY);
}

int getParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = getParent(parent[x]);
}

bool checkParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x == y) return true;
	else return false;
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main() {
	int i, j;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		coord.push_back(make_pair(a, b));
	}

	// 입력 받은 모든 좌표끼리의 거리를 우선 구한다.
	for (i = 0; i < coord.size(); i++) {
		double x1 = coord[i].first;
		double y1 = coord[i].second;
		
		for (j = i + 1; j < coord.size(); j++) {
			double x2 = coord[j].first;
			double y2 = coord[j].second;

			double distance = calDistance(x1, y1, x2, y2);
			Edge.push_back({ distance, {i, j} });
		}
	}

	// 계산한 정보를 바탕으로 MST 활용해서 별자리 만들어준다.
	for (i = 0; i < n; i++) parent[i] = i;

	sort(Edge.begin(), Edge.end());

	for (i = 0; i < Edge.size(); i++) {
		double cost = Edge[i].first;
		int p1 = Edge[i].second.first;
		int p2 = Edge[i].second.second;

		if (!checkParent(p1, p2)) {
			unionParent(p1, p2);
			res += cost;
		}
	}
	cout.precision(2);
	cout << res << "\n";

	return 0;
}