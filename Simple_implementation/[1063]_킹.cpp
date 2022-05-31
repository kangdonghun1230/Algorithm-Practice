/*
	Date: 2022/06/01
	Brief:
	Implementation
	Reference:
*/
#include <iostream>
#include <string>

#define MAX 9

using namespace std;

string stone_site, king_site;

int n;
// array for direction
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool inRange(int x, int y) {
	return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

int arrow(string move) {
    if (move == "T") {
        return  0;
    }
    else if (move == "RT") {
        return  1;
    }
    else if (move == "R") {
        return  2;
    }
    else if (move == "RB") {
        return  3;
    }
    else if (move == "B") {
        return  4;
    }
    else if (move == "LB") {
        return  5;
    }
    else if (move == "L") {
        return  6;
    }
    else if (move == "LT") {
        return  7;
    }
}

int main() {
	cin.tie(NULL);
	cin >> king_site >> stone_site >> n;

	pair<int, int> king = { king_site[1] - '0', king_site[0] - 'A' + 1 };
	pair<int, int> stone = { stone_site[1] - '0', stone_site[0] - 'A' + 1 };


	for (int i = 0; i < n; i++) {
		string move;

		cin >> move;
		
        int dir = arrow(move);

        pair<int, int> next_king = { king.first + dx[dir], king.second + dy[dir] };

        // if king's next position is out of range. -> skip current shift.
        if (!inRange(next_king.first, next_king.second)) continue;

        if (next_king == stone) {
            pair<int, int> next_stone = { stone.first + dx[dir], stone.second + dy[dir] };

            // if stone's next position is out of range. -> skip current shift
            if (!inRange(next_stone.first, next_stone.second)) continue;
            else stone = next_stone;
        }
        // king shift.
        king = next_king;
	}

    cout << char(king.second + 'A' - 1) << king.first << "\n";
    cout << char(stone.second + 'A' - 1) << stone.first << "\n";

	return 0;
}