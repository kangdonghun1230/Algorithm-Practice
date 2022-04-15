/*
	Date: 2022/04/15
	Brief:
	Dynamic programming
	Reference:
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001

using namespace std;

int expressWay[MAX];
vector<pair<int, int>> shortcut[MAX];

int main() {
	int n, d;
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> d;

	int sta, end, dis;
	for (i = 0; i < n; i++) {
		cin >> sta >> end >> dis;
		shortcut[end].push_back({sta, dis});
	}

	for (i = 1; i <= d; i++) {
		expressWay[i] = MAX;
	}
	expressWay[0] = 0;
	for (i = 1; i <= d; i++) {
		if (shortcut[i].size() == 0) {
			expressWay[i] = expressWay[i - 1] + 1;
		}
		else {
			for (auto it = shortcut[i].begin(); it != shortcut[i].end(); it++) {
				expressWay[i] = min(expressWay[i], expressWay[it->first] + it->second);
				expressWay[i] = min(expressWay[i], expressWay[i - 1] + 1);
			}
		}
	}

	cout << expressWay[d] << "\n";

	return 0;
}