/*
	Date: 2022/06/03
	Brief:
	Implementation
	Reference:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int max_res;
vector<pair<int, int>> points;
vector<pair<int, int>> sel_points;
int count_func = 0;

int cal_triangle(int a, int d, int b, int e, int c, int f) {
	int first = (a * e) + (b * f) + (c * d);
	int second = (d * b) + (e * c) + (f * a);
	//cout << first << " " << second << endl;
	
	int res = abs(first - second);

	return res;
}

void brute_force(int idx, int cnt) {
	if (cnt == 3) {
		int res = cal_triangle(sel_points[0].first, sel_points[0].second,
			sel_points[1].first, sel_points[1].second,
			sel_points[2].first, sel_points[2].second
		);
		count_func++;
		max_res = (max_res > res) ? max_res : res;
		return;
	}

	for (int i = idx; i < n; i++) {
		sel_points.push_back({ points[i].first, points[i].second });
		brute_force(i + 1, cnt + 1);
		sel_points.pop_back();
	}

	return;
}

int main() {
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		points.push_back(p);
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				max_res = max(max_res, cal_triangle(
					points[i].first, points[i].second,
					points[j].first, points[j].second,
					points[k].first, points[k].second
				));
			}
		}
	}*/

	brute_force(0, 0);

	if (max_res % 2)
		printf("%d.5\n", max_res / 2);
	else
		printf("%d\n", max_res / 2);


	return 0;
}