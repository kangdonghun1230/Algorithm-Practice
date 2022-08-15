/*
	Date: 2022/08/12
	Brief:
	
	Reference:
*/
#include <iostream>
#define MAX 51

using namespace std;

int n, m;
int r, c, d;
int res = 0;

// 북, 동, 남, 서
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
// 현재 방향을 기준으로 왼쪽은 index - 1


int map[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> r >> c >> d;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	// 시작 위치를 청소하고 출발한다. (청소한 뒤에는 2로 바꿔준다)
	map[r][c] = 2;
	res++;

	while (1) {
		bool washed = false;
		// 방향을 바꾸며 청소할 수 있는지 확인한다.
		for (int i = 0; i < 4; i++) {
			d -= 1;
			if (d == -1)
				d = 3;
			
			int nr = r + dx[d], nc = c + dy[d];

			// 청소할 수 있는 경우 다음 칸으로 넘어간다.
			if (map[nr][nc] == 0) {
				map[nr][nc] = 2;
				r = nr;
				c = nc;
				washed = true;
				res++;
				break;
			}
			// 벽이거나 청소한 경우 continue
			else {
				continue;
			}
		}
		// 청소할 수 없는 경우 후진
		int backward = d - 2;
		if (backward < 0)
			backward += 4;

		if (!washed && map[r + dx[backward]][c + dy[backward]] != 1) {
			r = r + dx[backward];
			c = c + dy[backward];
		}
		// 후진할 수 없는 경우 반복문 탈출
		else if(!washed) {
			break;
		}
	}

	cout << res << "\n";

	return 0;
}