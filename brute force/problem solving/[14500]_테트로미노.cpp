/*
	Date: 2022/02/20
	Brief:
	simple brute-force problem
	Reference:
	https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14500-%ED%85%8C%ED%8A%B8%EB%A1%9C%EB%AF%B8%EB%85%B8
*/
#include <iostream>
#define MAX 501

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int arrX[4] = { 0, 0, 1, -1 };
int arrY[4] = { 1, -1, 0, 0 };
int cur[5];
int maxDistance = 0;

int n, m;

bool inRange(int x, int y) {
	if (x <= 0 || x > n || y <= 0 || y > m)
		return false;
	else
		return true;
}

void checkingTetromino(int x, int y, int sum, int num) {
	if (num == 4) {
		// if current combination is bigger than current maxDistance
		if (sum > maxDistance) {
			maxDistance = sum;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + arrX[i];
		int nextY = y + arrY[i];

		if (!inRange(nextX, nextY))
			continue;
		
		if (visited[nextX][nextY]) {
			continue;
		}
		else {
			visited[nextX][nextY] = true;
			checkingTetromino(nextX, nextY, sum + map[nextX][nextY], num + 1);
			visited[nextX][nextY] = false;
		}
	}
	return;
}

void checkingParticular(int x, int y) {
	int sum = 0;
	// 1. ㅜ
	if (inRange(x, y + 1) && inRange(x, y + 2) && inRange(x + 1, y + 1)) {
		sum = (map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
		maxDistance = maxDistance > sum ? maxDistance : sum;
	}
	// 2. ㅏ
	if (inRange(x + 1, y) && inRange(x + 2, y) && inRange(x + 1, y + 1)) {
		sum = (map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
		maxDistance = maxDistance > sum ? maxDistance : sum;
	}
	// 3. ㅗ
	if (inRange(x, y + 1) && inRange(x - 1, y + 1) && inRange(x, y + 2)) {
		sum = (map[x][y] + map[x][y + 1] + map[x - 1][y + 1] + map[x][y + 2]);
		maxDistance = maxDistance > sum ? maxDistance : sum;
	}
	// 4. ㅓ
	if (inRange(x, y + 1) && inRange(x - 1, y + 1) && inRange(x + 1, y + 1)) {
		sum = (map[x][y] + map[x][y + 1] + map[x - 1][y + 1] + map[x + 1][y + 1]);
		maxDistance = maxDistance > sum ? maxDistance : sum;
	}
	return;
}

int main() {
	int i, j;
	cin.tie(NULL);

	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			visited[i][j] = true;
			checkingTetromino(i, j, map[i][j], 1);
			visited[i][j] = false;
			checkingParticular(i, j);
		}
	}

	cout << maxDistance << "\n";


	return 0;
}

/*
	4개의 정사각형이 이어져있는 경우 -> 테트로미노라고 부른다.

	주어진 맵에서 테트로미노 하나 놓았을 때, 최고점이 되는 경우의
	점수를 return하면 된다.

	reference 참고해서 ㅗ, ㅜ, ㅓ, ㅏ case를 따로 살펴야 함을 알았다.
*/