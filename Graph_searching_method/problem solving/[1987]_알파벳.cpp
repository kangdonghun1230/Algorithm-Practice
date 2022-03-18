/*
	Date: 2022/03/04
	Brief:
	Back tracking problem
	Reference:
	https://wooono.tistory.com/307
*/
#include <iostream>
#include <string>
#include <algorithm>
#define MAX 21

using namespace std;

string board[MAX];
int r, c;
bool checkAlpha[26]; // 0:A, 1:B, 2:C, 3:D ~ 25:Z

int arrX[4] = { 0, 0, 1, -1 };
int arrY[4] = { 1, -1, 0, 0 };
int res = 0;

bool checkRange(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c) return false;
	else return true;
}

void DFS(int x, int y, int cur) {
	// change the result if current one is bigger.
	res = max(cur, res);

	for (int i = 0; i < 4; i++) {
		int nextX = x + arrX[i];
		int nextY = y + arrY[i];

		if (checkRange(nextX, nextY) && !checkAlpha[board[nextX][nextY] - 'A']) {
			checkAlpha[board[nextX][nextY] - 'A'] = true;
			DFS(nextX, nextY, cur + 1);
			checkAlpha[board[nextX][nextY] - 'A'] = false;
		}
	}
	return;
}

int main() {
	int i;
	cin.tie(NULL);

	cin >> r >> c;
	for (i = 0; i < r; i++) {
		cin >> board[i];
	}
	checkAlpha[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);

	cout << res << "\n";

	return 0;
}