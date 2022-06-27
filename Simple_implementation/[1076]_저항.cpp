/*
	Date: 2022/06/27
	Brief:
	Implementation
	Reference:
*/
#include <iostream>
#include <string>

using namespace std;

// array of colors
string colors[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int main() {
	// save input strings
	string col1, col2, col3;
	long long res = 0;
	cin.tie(NULL);

	cin >> col1;
	for (int i = 0; i < 10; i++) {
		if (col1 == colors[i])
			res += i;
	}
	res *= 10;

	cin >> col2;
	for (int i = 0; i < 10; i++) {
		if (col2 == colors[i]) {
			res += i;
		}
	}

	long long pow = 1;
	cin >> col3;
	for (int i = 0; i < 10; i++) {
		if (col3 == colors[i]) {
			break;
		}
		pow *= 10;
	}
	cout << res * pow << endl;

	return 0;
}