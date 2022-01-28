/*
	Date: 2022/01/28
	Brief:
	Simple program for matching string with maximum same words.
	Reference:
*/

#include <iostream>
#include <string>
#define MAX 50

using namespace std;

string str[MAX];
string strMaxLen;

int main() {
	cin.tie(NULL);
	// n: the number of strings, len: the length of each string
	int n, len;
	int i, j;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> str[i];
	}
	len = str[0].length();
	strMaxLen = str[0];

	for (i = 1; i < n; i++) {
		for (j = 0; j < len; j++) {
			if (strMaxLen[j] == str[i][j])
				continue;
			else
				strMaxLen[j] = '?';
		}
		//cout << strMaxLen << endl;
	}
	cout << strMaxLen << endl;

	return 0;
}

