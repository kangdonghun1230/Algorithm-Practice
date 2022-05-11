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
// 사다리 정보와 뱀의 정보를 저장하는 배열 생성, 둘을 동시에 가질 수는 없음
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

			// 사다리를 타는 경우
			if (ladder[next_x] != 0) {
				next_x = ladder[next_x];
			}
			// 뱀을 타는 경우
			else if (snake[next_x] != 0) {
				next_x = snake[next_x];
			}

			// 사다리도 뱀도 타지 않았지만, 처음 방문한 경우
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
		// x번 칸에 도착하면, y번 칸으로 이동
		ladder[x] = y;
	}

	for (i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		// u번 칸에 도착하면, v번 칸으로 이동
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