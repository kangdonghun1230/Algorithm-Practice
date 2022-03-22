/*
	Date: 2022/03/22
	Brief:
	back tracking example
	Reference:
*/
#include <iostream>
#include <string>

using namespace std;

string sudoku[9];
// 각 row, column, square에서 숫자의 존재 여부를 판단하는 배열
bool row[10][10], col[10][10], square[10][10];

void solve(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			cout << sudoku[i] << "\n";
		}
		// 답을 하나만 출력하기 위해 process를 종료하는 system call 호출
		exit(0);
	}

	int x = cnt / 9; // row axis
	int y = cnt % 9; // col axis
	int num = (x / 3) * 3 + (y / 3);
	if (sudoku[x][y] == '0') {
		for (int i = 1; i <= 9; i++) {
			// 현재 칸에 들어갈 수 있는 숫자인 경우
			if (!row[x][i] && !col[y][i] && !square[num][i]) {
				// 해당 숫자로 방문 처리
				row[x][i] = true;
				col[y][i] = true;
				square[num][i] = true;
				sudoku[x][y] = '0' + i;
				solve(cnt + 1);
				// 방문 처리 해제
				row[x][i] = false;
				col[y][i] = false;
				square[num][i] = false;
				sudoku[x][y] = '0';
			}
		}
	}
	else {
		solve(cnt + 1);
		return;
	}
}

int main() {
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (i = 0; i < 9; i++) {
		cin >> sudoku[i];

		// set the status data of row, col, square information
		for (j = 0; j < 9; j++) {
			int num = sudoku[i][j] - '0';
			if (num == 0)
				continue;
			else {
				row[i][num] = true;
				col[j][num] = true;
				
				int square_num = (i / 3) * 3 + (j / 3);
				square[square_num][num] = true;
			}
		}
	}

	solve(0);

	return 0;
}