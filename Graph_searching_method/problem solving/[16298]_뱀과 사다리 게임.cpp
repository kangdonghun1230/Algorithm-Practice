/*
	Date: 2022/05/11
	Brief:
	BFS
	Reference:
*/
#include <iostream>
#include <queue>

using namespace std;

// game board
int board[101];
// ��ٸ� ������ ���� ������ �����ϴ� �迭 ����, ���� ���ÿ� ���� ���� ����
int ladder[101];
int snake[101];
int visited[101];

int n, m;

void BFS() {
	queue<int> q;

	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next_x = x + i;
			
			if (next_x > 100 || visited[next_x] != 0)
				continue;

			// ��ٸ��� Ÿ�� ���
			if (ladder[next_x] != 0) {
				next_x = ladder[next_x];
			}
			// ���� Ÿ�� ���
			else if (snake[next_x] != 0) {
				next_x = snake[next_x];
			}

			// ��ٸ��� �쵵 Ÿ�� �ʾ�����, ó�� �湮�� ���
			if(visited[next_x] == 0) {
				visited[next_x] = visited[x] + 1;
				q.push(next_x);
			}
		}
	}
	
	return;
}

int main() {
	int i, j;
	cin >> n >> m;

	for (i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		// x�� ĭ�� �����ϸ�, y�� ĭ���� �̵�
		ladder[x] = y;
	}

	for (i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		// u�� ĭ�� �����ϸ�, v�� ĭ���� �̵�
		snake[u] = v;
	}
	BFS();

	if (visited[100] == 0) {
		cout << "-1\n";
	}
	else {
		cout << visited[100] - 1 << endl;
	}
	return 0;
}