/*
	Date: 2022/02/10
	Brief:
	Searching for the shortest way with graph searching
	method (like DFS, BFS)
	Reference:
	https://www.acmicpc.net/board/view/27386
	https://kscodebase.tistory.com/66
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int n, m;

int map[MAX][MAX];

int arr_x[4] = { 0, 0, 1, -1 };
int arr_y[4] = { 1, -1, 0, 0 };

int visited[MAX][MAX][2];

typedef struct pos {
	int x, y;
	// breakingWall=false -> 부술 수 없다.
	// breakingWall=true -> 한 번은 부술 수 있다.
	bool breakingWall;
};

bool inTheRange(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	else
		return true;
}

int BFS() {
	int i, j;
	queue<pos> q;
	visited[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		// if we successfully arrived to the destination. return the current distance.
		if (cur.x == n - 1 && cur.y == m - 1) return visited[cur.x][cur.y][cur.breakingWall];

		for (i = 0; i < 4; i++) {
			pos next;
			next.x = cur.x + arr_x[i];
			next.y = cur.y + arr_y[i];
			next.breakingWall = cur.breakingWall;

			// Checking if the next position is out of the range.
			if (!inTheRange(next.x, next.y)) {
				continue;
			}

			// If this position is already visited, skip this case. (어차피 최단거리 아님)
			if (visited[next.x][next.y][next.breakingWall]) {
				continue;
			}

			if (map[next.x][next.y] == 0) {
				visited[next.x][next.y][next.breakingWall] = visited[cur.x][cur.y][cur.breakingWall] + 1;
				q.push(next);
			}
			if (map[next.x][next.y] == 1 && cur.breakingWall == 0) {
				next.breakingWall = true;
				visited[next.x][next.y][1] = visited[cur.x][cur.y][cur.breakingWall] + 1;
				q.push(next);
			}
		}
	}
	// Couldn't reach to the final destination
	return -1;
}


int main() {
	int i, j;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d\n", BFS());


	return 0;
}

/*
새로 공부한 내용들
- scanf에서 %1d로 입력 받아서 한 자리씩 입력할 수 있다.
- 가중치가 없는 최단거리 문제는 무조건 BFS로 풀어야 한다.
*/