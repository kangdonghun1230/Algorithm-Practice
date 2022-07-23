/*
	Date: 2022/07/20
	Brief:
	Dijkstra
	Reference:
*/
#include <iostream>
#include <string>
#include <queue>

#define MAX 51
#define INF 2501
using namespace std;

string houseInfo[MAX];
int res = INF;

int n;
// 0(��), 1(��), 2(��), 3(��)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// ���� �Ÿ����� ���� ������ �ƴ� ��� ������ �� �ִ�. (�ߺ� ó���� ���� ���ؼ� �ʿ��ϴٰ� ��)
// ��� �׳� �̹� ������ �ּڰ��� �Ѿ�� ���Ѵٴ� �������� �����ص� ���� ������ �ʹ�.
bool visited[MAX][MAX][2501][4] = {false,};

vector<pair<int, int>> doorSite;

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void BFS(int x, int y) {
	// pair<pair<�ſ� ��, ����>, pair<x, y>>
	queue<pair<pair<int, int>, pair<int, int>>> q;

	// ù ���� 4������ queue�� �־��ش�.
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		int next_g = 0;
		int next_d = i;

		if (!inRange(next_x, next_y))
			continue;
		// ���� ĭ�� ���� ��� ��ŵ
		if (houseInfo[next_x][next_y] == '*')
			continue;
		visited[next_x][next_y][next_g][next_d] = true;
		q.push({ {next_g, next_d}, {next_x, next_y} });
	}

	while (!q.empty()) {
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;

		int cur_g = q.front().first.first;
		int cur_d = q.front().first.second;
		q.pop();

		if (cur_g > res)
			continue;

		//cout << cur_x << " " << cur_y << " " << cur_g << " " << cur_d << endl;
		// ���� ĭ�� ���� ���
		if (houseInfo[cur_x][cur_y] == '#' && cur_x == doorSite[1].first && cur_y == doorSite[1].second) {
			// ���� ������ ��� ���� �������� �Ǵ��Ѵ�.
			res = (res > cur_g) ? cur_g : res;
			continue;
		}
		else if (houseInfo[cur_x][cur_y] == '.') {
			// �� ������ ��� ���� ���� �״�� �����Ѵ�.
			int next_x = cur_x + dx[cur_d];
			int next_y = cur_y + dy[cur_d];

			int next_g = cur_g;
			int next_d = cur_d;

			if (!inRange(next_x, next_y))
				continue;
			// ���� ĭ�� ���� ��� ��ŵ or �̹� �湮�� ��� ��ŵ
			if (houseInfo[next_x][next_y] == '*' || visited[next_x][next_y][next_g][next_d])
				continue;
			visited[next_x][next_y][next_g][next_d] = true;
			q.push({ {next_g, next_d}, {next_x, next_y} });
		}
		else {
			// �ſ��� ��� �� ���� �������� Ʋ������. (���� ���� ���⿡ ���� or �״�� ����.)
			for (int i = 0; i < 4; i++) {
				if (cur_d == 0 && i == 1)
					continue;
				if (cur_d == 1 && i == 0)
					continue;
				if (cur_d == 2 && i == 3)
					continue;
				if (cur_d == 3 && i == 2)
					continue;
				

				int next_x = cur_x + dx[i];
				int next_y = cur_y + dy[i];

				int next_g = cur_g;
				int next_d = i;

				//cout << "�ſ�: " << next_x << " " << next_y << " " << next_g << " " << next_d << endl;

				if (!inRange(next_x, next_y))
					continue;
				// ���� ĭ�� ���� ��� ��ŵ
				if (houseInfo[next_x][next_y] == '*')
					continue;

				// ���� ������ �ٲ�� ��� �ſ� ���� �߰��Ѵ�. (�ſ��� ��ġ�ϴ� ���)
				if (next_d != cur_d)
					next_g++;

				// �̹� �湮�� ��� ��ŵ�Ѵ�.
				if (visited[next_x][next_y][next_g][next_d])
					continue;

				visited[next_x][next_y][next_g][next_d] = true;
				//cout << "�ſ�" << next_x << " " << next_y << " " << next_g << " " << next_d << endl;
				q.push({ {next_g, next_d}, {next_x, next_y} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> houseInfo[i];
	}
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (houseInfo[i][j] == '#') {
				doorSite.push_back({ i, j });
			}
		}
	}
	BFS(doorSite[0].first, doorSite[0].second);

	cout << res << "\n";

	return 0;
}

/*
idea

�ſ��� ��ġ�� �� �ִ� ��ġ���� ���� �� �ִ� �ɼ�
1. �״�� ����
2. �ſ��� ��ġ�ϰ� + ���� ������ �ٲ۴� (2����)

�ſ��� ���� �� ����
1. �״�� ����

��
1. ������

��
1. 4���� �������� ���� ����

���� ���� ������ ť�� �ִ� ����� ���ͽ�Ʈ�� �˰����� Ȱ���ؾ� �� ������ ���δ�.

*������ ��
��� ������ ����� ���� �����ε�, �̰��� ���� ���� detect �Ǵ� ���� ��������� ��� ������ ������.

*/