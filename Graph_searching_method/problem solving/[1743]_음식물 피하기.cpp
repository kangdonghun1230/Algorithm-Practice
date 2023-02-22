#include <iostream>
#define MAX 101

using namespace std;

//세로, 가로, 음식물 쓰레기의 개수
int n, m, k;
//최대 음식물 쓰레기 크기를 저장하는 변수
int res = 0;
//현재 음식물 쓰레기 크기를 저장하는 변수
int cur_trash = 0;

int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inRange(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

void dfs(int x, int y) {
	//dfs 호출될때 마다 결과를 갱신해본다.
	res = (res > cur_trash) ? res : cur_trash;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!inRange(nx, ny))
			continue;

		//다음 칸이 음식물 쓰레기인 경우
		if (arr[nx][ny] == 1 && !visited[nx][ny]) {
			visited[nx][ny] = true;
			cur_trash++;
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		arr[x][y] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//방문하지 않은 음식물 쓰레기의 크기를 dfs로 측정한다.
			if (arr[i][j] == 1 && !visited[i][j]) {
				//방문 처리하고 현재 음식물 쓰레기의 크기를 1로 초기화한 상태로 dfs 호출
				visited[i][j] = true;
				cur_trash = 1;
				dfs(i, j);
			}
		}
	}

	cout << res;

	return 0;
}