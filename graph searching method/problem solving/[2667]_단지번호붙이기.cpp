/*
	Date: 2022/02/08
	Brief:
	simple graph traversal problem.
	Reference:
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 25

using namespace std;

int n;
string arr[MAX];
bool visited[MAX][MAX];
int arrX[4] = { 0, 0, 1, -1 };
int arrY[4] = {-1, 1, 0, 0};

vector<int> result;

bool inTheRange(int x, int y) {
	if ((x < 0 || x >= n) || (y < 0 || y >= n)) {
		return false;
	}
	else {
		if (arr[x][y] == '1') {
			return true;
		}
		else return false;
	}
}

void BFS(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	// out of the range
	
	q.push({ x, y });

	while (!q.empty()) {
		int next_x = q.front().first;
		int next_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (inTheRange(next_x + arrX[i], next_y + arrY[i])&& !visited[next_x + arrX[i]][next_y + arrY[i]]) {
				q.push({ next_x + arrX[i], next_y + arrY[i] });
				visited[next_x + arrX[i]][next_y + arrY[i]] = true;
				cnt++;
			}
		}
	}
	result.push_back(cnt);
}

int main() {
	int res = 0;
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != '0' && !visited[i][j]) {
				visited[i][j] = true;
				BFS(i, j);
				res++;
			}
		}
	}
	cout << res << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < res; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}