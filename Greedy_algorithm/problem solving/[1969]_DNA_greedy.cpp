#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001

using namespace std;

string dna[MAX];
string result;
int main() {
	int n, m, hammingDistance = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> dna[i];
	}
	sort(dna, dna + n);
	for (int i = 0; i < m; i++) {
		int a[4] = { 0, };
		for (int j = 1; j <= n; j++) {
			if (dna[j][i] == 'A') a[0]++;
			else if (dna[j][i] == 'C') a[1]++;
			else if (dna[j][i] == 'G') a[2]++;
			else if (dna[j][i] == 'T') a[3]++;
		}
		int idx = 0, max = 0;
		for (int j = 0; j < 4; j++) {
			if (max < a[j]) {
				idx = j;
				max = a[j];
			}
		}
		hammingDistance += (n - max);
		if (idx == 0) result += 'A';
		else if (idx == 1) result += 'C';
		else if (idx == 2) result += 'G';
		else if (idx == 3) result += 'T';
	}
	cout << result << "\n" << hammingDistance << "\n";

	return 0;
}

/*
동일한 hamming distance를 갖는 경우 사전순으로 출력하시오
라는 조건을 확인하지 않아 오답을 받았었다.
*/