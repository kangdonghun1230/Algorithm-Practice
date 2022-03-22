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
// �� row, column, square���� ������ ���� ���θ� �Ǵ��ϴ� �迭
bool row[10][10], col[10][10], square[10][10];

void solve(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			cout << sudoku[i] << "\n";
		}
		// ���� �ϳ��� ����ϱ� ���� process�� �����ϴ� system call ȣ��
		exit(0);
	}

	int x = cnt / 9; // row axis
	int y = cnt % 9; // col axis
	int num = (x / 3) * 3 + (y / 3);
	if (sudoku[x][y] == '0') {
		for (int i = 1; i <= 9; i++) {
			// ���� ĭ�� �� �� �ִ� ������ ���
			if (!row[x][i] && !col[y][i] && !square[num][i]) {
				// �ش� ���ڷ� �湮 ó��
				row[x][i] = true;
				col[y][i] = true;
				square[num][i] = true;
				sudoku[x][y] = '0' + i;
				solve(cnt + 1);
				// �湮 ó�� ����
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