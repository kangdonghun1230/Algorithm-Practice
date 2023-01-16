#include <iostream>
#include <queue>

#define MAX_N 51
#define MAX 2501

using namespace std;

int n;
string m[MAX_N];
int d[MAX_N][MAX_N]; //�� ���������� �ּ� �� ���� ��ȯ ���� �����ϴ� 2���� �迭

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = MAX;
		}
	}
}

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void BFS() {
	init(); //�ּ� ���� �迭�� �ʱ�ȭ�ϰ� �����Ѵ�.
	queue<pair<int, pair<int, int>>> q;
	//������� queue�� �ִ´�.
	q.push({ 0, {0, 0} });
	d[0][0] = 0;

	while (!q.empty()) {
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;
		int cur_black_num = q.front().first;

		q.pop();

		//������ ���� �湮�ϸ鼭 �ּ� ������ ��ȯ ����� ����غ���.
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			int next_black_num = cur_black_num;

			if (!inRange(next_x, next_y))
				continue;

			if (m[next_x][next_y] == '0') {
				next_black_num++;
			}

			if (d[next_x][next_y] > next_black_num) {
				d[next_x][next_y] = next_black_num;
				q.push({ next_black_num, {next_x, next_y} });
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	BFS();

	cout << d[n - 1][n - 1];

	return 0;
}
//Ž���� �����ϸ鼭, ����ؾ��� cost�� ���� �� ���� ���� ���� �����Դ����̴�.
//���� ������ �����ϸ鼭 �����ϴ� ���� �ƴ϶� ���� ��ο��� �� ���� ���� ���� ���������� �߿�
