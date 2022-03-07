/*
	Date: 2022/03/07
	Brief:
	two pointer example
	Reference:
*/
#include <iostream>
#include <algorithm>
#define MAX 100001

const int INF = 1000000000;

using namespace std;

int arr[MAX];

int main() {
	int n, s, i;
	int start, end, sectionSum = 0;
	int len = INF;
	cin.tie(NULL);

	cin >> n >> s;
		
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sectionSum = arr[0];
	start = 0, end = 0;
	
	while (start <= end && end < n) {
		if (sectionSum < s) {
			sectionSum += arr[++end];
		}
		else if (sectionSum > s) {
			// ���� ���Ҹ� �ϳ� ������ �� ��� Ž���Ѵ�.
			len = min(len, end - start + 1);
			sectionSum -= arr[start++];
		}
		else { // sectionSum == s
			// ���� ���Ҹ� �ϳ� ������ �Ŀ� ��� Ž���Ѵ�.
			len = min(len, end - start + 1);
			sectionSum -= arr[start++];
		}
	}
	// ���� �� ���� ���
	if (len == INF) {
		cout << "0\n";
	}
	else {
		cout << len << "\n";
	}

	return 0;
}