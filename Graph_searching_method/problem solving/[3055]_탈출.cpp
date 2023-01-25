#include <iostream>
#include <queue>
#include <string>

#define MAX 51
#define MAX_VAL 2501

using namespace std;

int r, c;
int d, s;

string map[MAX];
int dp[MAX][MAX];

queue<pair<int, int>> q;
queue<pair<int, int>> waterQueue;

void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dp[i][j] = MAX_VAL;
		}
	}
}

bool inRange(int x, int y) {
	return (0 <= x && x < r && 0 <= y && y < c);
}

void findMinPath() {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	
	while (!q.empty()) {
		//���� ���� ������ ĭ�� Ž���ϱ� �����̴�.
		int waterQueueSize = waterQueue.size();
		for (int i = 0; i < waterQueueSize; i++) {

			int currentWaterX = waterQueue.front().first;
			int currentWaterY = waterQueue.front().second;
			waterQueue.pop();

			for (int j = 0; j < 4; j++) {
				int nextWaterX = currentWaterX + dx[j];
				int nextWaterY = currentWaterY + dy[j];

				//���� ������ Ȯ���Ѵ�.
				if (!inRange(nextWaterX, nextWaterY))
					continue;

				if (map[nextWaterX][nextWaterY] == '.') {
					//�ش� ĭ�� ���� ������
					map[nextWaterX][nextWaterY] = '*';
					waterQueue.push({ nextWaterX, nextWaterY });
				}
			}
		}
		int queueSize = q.size();

		for (int i = 0; i < queueSize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			int dis = dp[x][y];
			q.pop();

			//���������̸� �����Ѵ� (������ BFS)
			if (map[x][y] == 'D') {
				cout << dp[x][y];
				return;
			}

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				int nextDis = dis + 1;

				if (!inRange(nx, ny) || (nextDis >= dp[nx][ny]))
					continue;
				//���� ������ �����̰ų� ��� ������ ���� �ǳʶ��. (�� ����)
				if (map[nx][ny] == '*' || map[nx][ny] == 'S' || map[nx][ny] == 'X')
					continue;

				//�ִ� �ð� �����ϰ�, queue�� �ִ´�.
				dp[nx][ny] = nextDis;
				q.push({ nx, ny });
			}
		}
	}

	//�ᱹ �������� �������� ���� ��쿡 �ش��Ѵ�.
	cout << "KAKTUS";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int desX, desY;

	cin >> r >> c;

	init();

	for (int i = 0; i < r; i++) {
		string row;
		cin >> row;
		map[i] = row;

		for (int j = 0; j < c; j++) {
			if (row[j] == '*') {
				waterQueue.push({ i, j });
			}
			else if (row[j] == 'S') {
				q.push({ i, j });
				dp[i][j] = 0;
			}
		}
	}

	findMinPath();

	return 0;
}