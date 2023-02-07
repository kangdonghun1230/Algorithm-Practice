#include <iostream>
#define MAX 1001

using namespace std;

int n;
int boxArr[MAX];
int d[MAX];

void init() {
	for (int i = 0; i < n; i++) {
		cin >> boxArr[i];
	}

	//모든 박스는 일단 1개로 취급
	for (int i = 0; i < n; i++) {
		d[i] = 1;
	}
}

void dp() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (boxArr[i] > boxArr[j]) {
				d[i] = (d[i] < d[j] + 1) ? d[j] + 1 : d[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	init();
	dp();

	int maxResult = 1;

	for (int i = 0; i < n; i++) {
		maxResult = (maxResult > d[i]) ? maxResult : d[i];
	}

	cout << maxResult;

	return 0;
}