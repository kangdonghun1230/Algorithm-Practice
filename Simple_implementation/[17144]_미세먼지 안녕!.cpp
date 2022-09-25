/*
	Date: 2022/08/23
	Brief:

	Reference:
*/
#include <iostream>
#include <queue>

#define MAX 51

using namespace std;

int arr[MAX][MAX];
int r, c, t;

void input() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
}

// (x, y)가 맵 내부인지 확인하는 함수이다.
bool inRange(int x, int y) {
	return (0 <= x && x < r && 0 <= y && y < c);
}

void spreadDust() {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	queue<pair<int, pair<int, int>>> q;

	// 먼저 현재 시점 기준으로 모든 미세 먼지의 위치와 퍼질 양을 큐에 담는다.
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// 공기청정기는 건너 띈다.
			if (arr[i][j] == -1)
				continue;

			if (arr[i][j] != 0) {
				// 퍼질 미세먼지의 양과 위치를 큐에 담는다.
				q.push({ arr[i][j] / 5, {i, j} });
			}
		}
	}

	// queue에 담긴 미세먼지를 가능한 방향으로 한 번에 퍼뜨린다.
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int spreadDustAmount = q.front().first;

		q.pop();
		//cout << x << " " << y << " " << spreadDustAmount << endl;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!inRange(nx, ny) || arr[nx][ny] == -1)
				continue;

			// 퍼진 만큼 해당 칸은 미세먼지가 증하고 원래 칸에는 줄어든다.
			arr[nx][ny] += spreadDustAmount;
			arr[x][y] -= spreadDustAmount;
		}
	}
}

void airfresherOn() {
	int first = 0, second = 1;

	// 우, 상, 좌, 하 순으로 공기가 순환한다.
	int dx1[] = { 0, -1, 0, 1 };
	int dy1[] = { 1, 0, -1, 0 };

	// 공기 청정기의 위치를 찾는다.
	for (int i = 0; i < r; i++) {
		if (arr[i][0] == -1) {
			first = i, second = i + 1;
			break;
		}
	}

	int x = first, y = 0;
	int prev = 0;
	int idx = 0;

	// 공기 청정기로 돌아올때까지 훑는다.
	while (1) {
		int nx = x + dx1[idx], ny = y + dy1[idx];
		
		// 맵의 끝을 넘어가면 탐색 방향을 바꾼다.
		if (!inRange(nx, ny)) {
			idx++;
			continue;
		}

		// 다시 공기청정기에 도달하면 공기 순환을 멈춘다.
		if (nx == first && ny == 0)
			break;

		// 해당 칸의 공기를 이동시키고 칸의 위치도 이동한다.
		int cur = arr[nx][ny];
		arr[nx][ny] = prev;
		prev = cur;
		x = nx, y = ny;
	}

	// 우, 하, 좌, 상 순으로 공기가 순환한다.
	int dx2[] = { 0, 1, 0, -1 };
	int dy2[] = { 1, 0, -1, 0 };


	x = second, y = 0;
	prev = 0;
	idx = 0;

	// 공기 청정기로 돌아올때까지 훑는다.
	while (1) {
		int nx = x + dx2[idx], ny = y + dy2[idx];

		// 맵의 끝을 넘어가면 탐색 방향을 바꾼다.
		if (!inRange(nx, ny)) {
			idx++;
			continue;
		}

		// 다시 공기청정기에 도달하면 공기 순환을 멈춘다.
		if (nx == second && ny == 0)
			break;

		// 해당 칸의 공기를 이동시키고 칸의 위치도 이동한다.
		int cur = arr[nx][ny];
		arr[nx][ny] = prev;
		prev = cur;
		x = nx, y = ny;
	}

	return;
}

int totalDustAmount() {
	int res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == -1)
				continue;
			res += arr[i][j];
		}
	}
	return res;
}

void printStatus() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> t;

	input();
	
	while (t--) {
		spreadDust();
		airfresherOn();
	}

	//printStatus();

	cout << totalDustAmount();
	return 0;
}