#include <iostream>
#include <string>

using namespace std;

bool finded[6];

bool rabinKarp(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();

	int parentHash = 0, patternHash = 0, pow = 1;

	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				// this index (patternSize - 1) point to last element
				parentHash += parent[patternSize - 1 - j] * pow;
				patternHash += pattern[patternSize - 1 - j] * pow;
				
				if (j < patternSize - 1) pow *= 2;
			}
		}
		else {
			// i is starting point of hash string
			// next parent hash = 2 * (origin hash - original first element * pow) - new element
			parentHash = 2 * (parentHash - parent[i - 1] * pow) + parent[i + patternSize - 1];
		}

		if (parentHash == patternHash) {
			bool finded = true;

			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) finded = false;
			}

			if (finded) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	string FBI = "FBI";
	bool isThere = false;
	for (int i = 1; i <= 5; i++) {
		string name;
		cin >> name;
		if (rabinKarp(name, FBI)) {
			isThere = true;
			finded[i] = true;
		}
	}

	if (!isThere) {
		cout << "HE GOT AWAY!" << endl;
	}
	else {
		for (int i = 1; i <= 5; i++) {
			if (finded[i]) cout << i << " ";
		}
	}

	return 0;
}