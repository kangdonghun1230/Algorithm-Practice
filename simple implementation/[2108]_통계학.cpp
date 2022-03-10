/*
	Date: 2022/03/10
	Brief:
	simple implementation problem
	Reference:
	https://cocoon1787.tistory.com/357
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 500001
#define INF 4001
using namespace std;

int arr[MAX];
int cnt[8001];
int minNum = INF, maxNum = -INF;
int sum = 0;

int main() {
	int n;
	int i;
	cin.tie(NULL);

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];

		// get the range of input array
		minNum = arr[i] < minNum ? arr[i] : minNum;
		maxNum = arr[i] > maxNum ? arr[i] : maxNum;
		// calculate the summation of input array.
		sum += arr[i];
		// count the number of each elements
		cnt[arr[i] + 4000]++;
	}

	int frequency = 0;
	int mostFruentNum = 0;
	for (i = 0; i < 8001; i++) {
		frequency = frequency < cnt[i] ? cnt[i] : frequency;
	}
	int counter = 0;
	int idx = 0;
	for (i = 0; i < 8001; i++) {
		if (cnt[i] == frequency) {
			if (counter == 0) {
				idx = i;
				counter++;
			}
			else if (counter == 1) {
				idx = i;
				break;
			}
		}
	}

	sort(arr, arr + n);
	int mid = round(n / 2);

	cout << (int)round(sum / (double)n) << "\n";

	cout << arr[mid] << "\n";

	cout << idx - 4000 << "\n";

	cout << maxNum - minNum << "\n";

	return 0;
}