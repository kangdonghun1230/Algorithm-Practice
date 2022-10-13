#include <iostream>
#include <queue>

#define MAX 21

using namespace std;

int n;
int board[MAX][MAX];
int move_board[MAX][MAX];
int max_res = 0;

void moveBoard(int dir) {
	// 0: 왼, 1: 위, 2: 오, 3: 아
	queue<int> q;
	if (dir == 0) {
		for (int i = 1; i <= n; i++) {
			int idx = 1;
			for (int j = 1; j <= n; j++) {
				if(board[i][j] != 0)
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			while (!q.empty()) {
				int x = q.front();
				q.pop();

				// queue에서 하나씩 뽑아서 같으면 더하고 0이면 놓고 떠난다.
				// 이미 차있고 다른 숫자인 경우 다음 칸으로 이동
				if (board[i][idx] == 0) {
					board[i][idx] = x;
				}
				else if (board[i][idx] == x) {
					board[i][idx++] += x;
				}
				else {
					board[i][++idx] = x;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = 1; i <= n; i++) {
			int idx = 1;
			for (int j = 1; j <= n; j++) {
				if (board[j][i] != 0)
					q.push(board[j][i]);
				board[j][i] = 0;
			}

			while (!q.empty()) {
				int x = q.front();
				q.pop();

				// queue에서 하나씩 뽑아서 같으면 더하고 0이면 놓고 떠난다.
				// 이미 차있고 다른 숫자인 경우 다음 칸으로 이동
				if (board[idx][i] == 0) {
					board[idx][i] = x;
				}
				else if (board[idx][i] == x) {
					board[idx++][i] += x;
				}
				else {
					// 다른 숫자는 새로운 칸에 쌓는다.
					board[++idx][i] = x;
				}
			}
		}
	}
	else if (dir == 2) {
		for (int i = 1; i <= n; i++) {
			int idx = n;
			for (int j = n; j >= 1; j--) {
				if (board[i][j] != 0)
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			while (!q.empty()) {
				int x = q.front();
				q.pop();

				// queue에서 하나씩 뽑아서 같으면 더하고 0이면 놓고 떠난다.
				// 이미 차있고 다른 숫자인 경우 다음 칸으로 이동
				if (board[i][idx] == 0) {
					board[i][idx] = x;
				}
				else if (board[i][idx] == x) {
					board[i][idx--] += x;
				}
				else {
					board[i][--idx] = x;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			int idx = n;
			for (int j = n; j >= 1; j--) {
				if (board[j][i] != 0)
					q.push(board[j][i]);
				board[j][i] = 0;
			}

			while (!q.empty()) {
				int x = q.front();
				q.pop();

				// queue에서 하나씩 뽑아서 같으면 더하고 0이면 놓고 떠난다.
				// 이미 차있고 다른 숫자인 경우 다음 칸으로 이동
				if (board[idx][i] == 0) {
					board[idx][i] = x;
				}
				else if (board[idx][i] == x) {
					board[idx--][i] += x;
				}
				else {
					board[--idx][i] = x;
				}
			}
		}
	}

	return;
}

int getMaxBoard() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res = (res > board[i][j]) ? res : board[i][j];
		}
	}
	return res;
}

void DFS(int cnt) {
	if (cnt == 5) {
		int max_num = getMaxBoard();
		max_res = (max_res > max_num) ? max_res : max_num;

		return;
	}
	int copy_board[MAX][MAX];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			copy_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		moveBoard(i);
		DFS(cnt + 1);
		// 원상복구 시켜서 다른 방향으로 실행
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				board[i][j] = copy_board[i][j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	DFS(0);

	cout << max_res;
	
	return 0;
}