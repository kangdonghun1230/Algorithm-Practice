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
			// 앞의 원소를 하나 제거한 후 계속 탐색한다.
			len = min(len, end - start + 1);
			sectionSum -= arr[start++];
		}
		else { // sectionSum == s
			// 앞의 원소를 하나 제거한 후에 계속 탐색한다.
			len = min(len, end - start + 1);
			sectionSum -= arr[start++];
		}
	}
	// 만들 수 없는 경우
	if (len == INF) {
		cout << "0\n";
	}
	else {
		cout << len << "\n";
	}

	return 0;
}