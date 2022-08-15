/*
	Date: 2022/08/15
	Brief:
	Implementation
	Reference:
*/
#include <iostream>
#include <vector>
#include <cmath>

#define MAX 51
#define INF 101

using namespace std;

int n, m;
int arr[MAX][MAX];
int ans = INF * MAX;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<int> chicken_sites;

int solve();

int calDistance(int x, int y, int nx, int ny) {
	return abs(x - nx) + abs(y - ny);
}

void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) {
				houses.push_back({ i, j });
			}
			else if (arr[i][j] == 2) {
				chickens.push_back({ i, j });
			}
		}
	}

	return;
}

void pickChickens(int idx, int cnt) {
	if (cnt == m) {
		int res = solve();
		ans = (ans < res) ? ans : res;
		return;
	}
	else if (idx >= chickens.size()) {
		return;
	}

	chicken_sites.push_back(idx);
	pickChickens(idx + 1, cnt + 1);

	chicken_sites.pop_back();
	pickChickens(idx + 1, cnt);

	return;
}

int solve() {
	// 집에서 m개의 치킨 집까지의 거리를 모두 구한 후에 최소 거리를 비교한다.
	// 총 합인 치킨 거리를 구해서 현재 상황에서의 치킨 거리를 반환한다.
	int res = 0;

	for (int i = 0; i < houses.size(); i++) {
		int x = houses[i].first, y = houses[i].second;
		int minDis = INF;

		for (int j = 0; j < chicken_sites.size(); j++) {
			int nx = chickens[chicken_sites[j]].first, ny = chickens[chicken_sites[j]].second;
			int dis = calDistance(x, y, nx, ny);

			minDis = (minDis < dis) ? minDis : dis;
		}

		res += minDis;
	}
	return res; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	input();

	pickChickens(0, 0);

	cout << ans << endl;

	return 0;
}