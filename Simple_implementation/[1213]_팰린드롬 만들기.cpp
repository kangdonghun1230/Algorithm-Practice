#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string sryStr = "I'm Sorry Hansoo";
int alphabet[26];

int main() {
	string inputStr;
	string resStr;

	cin.tie(NULL);
	cin >> inputStr;

	int length = inputStr.length();

	for (int i = 0; i < length; i++) {
		// counting the number of alphabet
		alphabet[inputStr[i] - 'A']++;
	}

	// ¦��
	if (length % 2 == 0) {
		bool isOdd = false;
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] % 2 == 1)
				isOdd = true;
		}

		if (isOdd) {
			cout << sryStr << "\n";
			return 0;
		}

		string resSub = "";

		for (int i = 0; i < 26; i++) {
			if (alphabet[i] != 0) {
				for (int j = 0; j < alphabet[i] / 2; j++) {
					resSub += ('A' + i);
				}
			}
		}

		resStr = resSub;
		reverse(resSub.begin(), resSub.end());
		resStr += resSub;
		cout << resStr << "\n";
	}
	// Ȧ��
	else {
		int isOdd = 0;

		for (int i = 0; i < 26; i++) {
			if (alphabet[i] % 2 == 1)
				isOdd++;
		}
		
		if (isOdd > 1) {
			cout << sryStr << "\n";
			return 0;
		}

		int oddIdx;

		string resSub = "";

		for (int i = 0; i < 26; i++) {
			if (alphabet[i] != 0) {
				for (int j = 0; j < alphabet[i] / 2; j++) {
					resSub += ('A' + i);
				}
			}
			// Ȧ���� ��� index�� ����Ѵ�.
			if (alphabet[i] % 2 == 1)
				oddIdx = i;
		}

		resStr = resSub;
		resStr += (oddIdx + 'A');
		reverse(resSub.begin(), resSub.end());
		resStr += resSub;

		cout << resStr << "\n";
	}

	return 0;
}

/*
�� ���̰� Ȧ��: �ϳ��� ���� Ȧ����, ������ ¦����
�� ���̰� ¦��: ��� ���ڰ� ¦����
*/