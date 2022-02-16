/*
	Date: 2022/02/16
	Brief:
	simple implementation problem
	Reference:
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

struct pos {
	int x, y;
	bool operator<(const pos& a);
};

bool pos::operator<(const pos& a) {
	if (this->x > a.x)
		return false;
	else if (this->x == a.x && (this->y > a.y || this->y == a.y))
		return false;
	else
		return true;
}

int main() {
	pos* position = new pos[MAX];
	int n, i;
	cin.tie(NULL);
	cin >> n;

	for(i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		position[i].x = x;
		position[i].y = y;
	}
	sort(position, position + n);

	for (i = 0; i < n; i++) {
		cout << position[i].x << " " << position[i].y << "\n";
	}

	return 0;
}