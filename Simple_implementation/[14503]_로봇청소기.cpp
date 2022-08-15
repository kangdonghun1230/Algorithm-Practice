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

// ��, ��, ��, ��
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
// ���� ������ �������� ������ index - 1


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

	// ���� ��ġ�� û���ϰ� ����Ѵ�. (û���� �ڿ��� 2�� �ٲ��ش�)
	map[r][c] = 2;
	res++;

	while (1) {
		bool washed = false;
		// ������ �ٲٸ� û���� �� �ִ��� Ȯ���Ѵ�.
		for (int i = 0; i < 4; i++) {
			d -= 1;
			if (d == -1)
				d = 3;
			
			int nr = r + dx[d], nc = c + dy[d];

			// û���� �� �ִ� ��� ���� ĭ���� �Ѿ��.
			if (map[nr][nc] == 0) {
				map[nr][nc] = 2;
				r = nr;
				c = nc;
				washed = true;
				res++;
				break;
			}
			// ���̰ų� û���� ��� continue
			else {
				continue;
			}
		}
		// û���� �� ���� ��� ����
		int backward = d - 2;
		if (backward < 0)
			backward += 4;

		if (!washed && map[r + dx[backward]][c + dy[backward]] != 1) {
			r = r + dx[backward];
			c = c + dy[backward];
		}
		// ������ �� ���� ��� �ݺ��� Ż��
		else if(!washed) {
			break;
		}
	}

	cout << res << "\n";

	return 0;
}