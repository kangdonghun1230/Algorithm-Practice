/*
	Date: 2022/02/21
	Brief:
	simple brute-force problem
	Reference:
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int x, y;

	bool operator<(pos& a) {
		if (this->y < a.y) {
			return true;
		}
		else if (this->y == a.y && this->x < a.x) {
			return true;
		}
		else
			return false;
	}
};

int main() {
	int n, i;
	vector<pos> v;
	cin.tie(NULL);

	cin >> n;

	for(i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pos a;
		a.x = x;
		a.y = y;

		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (auto it = v.begin(); it != v.end(); it++) {
		cout << it->x << " " << it->y << "\n";
	}

	return 0;
}