#include <iostream>
#define MAX 21

using namespace std;

int w_arr[MAX][MAX][MAX];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		if (w_arr[20][20][20] != 0)
			return w_arr[20][20][20];
		else
			return w(20, 20, 20);
	}
	else if (a < b && b < c) {
		if (w_arr[a][b][c] != 0) 
			return w_arr[a][b][c];
		else 
			return w_arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		if (w_arr[a][b][c] != 0)
			return w_arr[a][b][c];
		else
			return w_arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main() {
	int a, b, c;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}

	return 0;
}