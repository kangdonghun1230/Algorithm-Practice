/*
	Date: 2022/02/15
	Brief:
	simple implementation problem
	Reference:
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	int cnt = 0;
	string str;
	cin.tie(NULL);

	// get the string with blank
	getline(cin, str);
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (i != 0 && i != str.length() - 1)
				cnt++;
		}
	}
	if (str.length() <= 1 && str[0] == ' ') 
		cout << cnt << "\n";
	else
		cout << cnt + 1 << "\n";

	return 0;
}