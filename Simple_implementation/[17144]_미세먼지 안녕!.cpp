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

// (x, y)�� �� �������� Ȯ���ϴ� �Լ��̴�.
bool inRange(int x, int y) {
	return (0 <= x && x < r && 0 <= y && y < c);
}

void spreadDust() {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	queue<pair<int, pair<int, int>>> q;

	// ���� ���� ���� �������� ��� �̼� ������ ��ġ�� ���� ���� ť�� ��´�.
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// ����û����� �ǳ� ���.
			if (arr[i][j] == -1)
				continue;

			if (arr[i][j] != 0) {
				// ���� �̼������� ��� ��ġ�� ť�� ��´�.
				q.push({ arr[i][j] / 5, {i, j} });
			}
		}
	}

	// queue�� ��� �̼������� ������ �������� �� ���� �۶߸���.
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

			// ���� ��ŭ �ش� ĭ�� �̼������� ���ϰ� ���� ĭ���� �پ���.
			arr[nx][ny] += spreadDustAmount;
			arr[x][y] -= spreadDustAmount;
		}
	}
}

void airfresherOn() {
	int first = 0, second = 1;

	// ��, ��, ��, �� ������ ���Ⱑ ��ȯ�Ѵ�.
	int dx1[] = { 0, -1, 0, 1 };
	int dy1[] = { 1, 0, -1, 0 };

	// ���� û������ ��ġ�� ã�´�.
	for (int i = 0; i < r; i++) {
		if (arr[i][0] == -1) {
			first = i, second = i + 1;
			break;
		}
	}

	int x = first, y = 0;
	int prev = 0;
	int idx = 0;

	// ���� û����� ���ƿö����� �ȴ´�.
	while (1) {
		int nx = x + dx1[idx], ny = y + dy1[idx];
		
		// ���� ���� �Ѿ�� Ž�� ������ �ٲ۴�.
		if (!inRange(nx, ny)) {
			idx++;
			continue;
		}

		// �ٽ� ����û���⿡ �����ϸ� ���� ��ȯ�� �����.
		if (nx == first && ny == 0)
			break;

		// �ش� ĭ�� ���⸦ �̵���Ű�� ĭ�� ��ġ�� �̵��Ѵ�.
		int cur = arr[nx][ny];
		arr[nx][ny] = prev;
		prev = cur;
		x = nx, y = ny;
	}

	// ��, ��, ��, �� ������ ���Ⱑ ��ȯ�Ѵ�.
	int dx2[] = { 0, 1, 0, -1 };
	int dy2[] = { 1, 0, -1, 0 };


	x = second, y = 0;
	prev = 0;
	idx = 0;

	// ���� û����� ���ƿö����� �ȴ´�.
	while (1) {
		int nx = x + dx2[idx], ny = y + dy2[idx];

		// ���� ���� �Ѿ�� Ž�� ������ �ٲ۴�.
		if (!inRange(nx, ny)) {
			idx++;
			continue;
		}

		// �ٽ� ����û���⿡ �����ϸ� ���� ��ȯ�� �����.
		if (nx == second && ny == 0)
			break;

		// �ش� ĭ�� ���⸦ �̵���Ű�� ĭ�� ��ġ�� �̵��Ѵ�.
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