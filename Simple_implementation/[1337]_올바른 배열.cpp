/*
	Date: 2022/07/14
	Brief:
	Implementation + sorting
	Reference:
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int n;
int minCnt = 4;

vector<int> arr(MAX, 0);

int main() {
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// sorting vector arr with sort function
	sort(arr.begin(), arr.begin() + n);

	for (int i = 0; i < n; i++) {
		int cnt = 5;

		vector<int> sample(5);

		// make sample array
		for (int j = 0; j < 5; j++) {
			sample[j] = arr[i] + j;
		}

		int k = 0;
		for (int j = 0; j < 5; j++) {
			if (k + i < n && sample[j] == arr[i + k]) {
				//cout << i + k << " " << arr[i + k] << endl;
				cnt--;
				k++;
			}
		}
		// minCnt를 갱신
		minCnt = (minCnt < cnt) ? minCnt : cnt;
	}

	cout << minCnt << "\n";

	return 0;
}

//---------------------------------------------

#include <iostream>
#include <algorithm>
#define MAX 51

using namespace std;

int n;
int arr[MAX] = { 0, };

int main() {
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		arr[i] = num;
	}
	sort(arr, arr + n);

	int max_cnt = 1;

	for (int i = 0; i < n; i++) {
		int cnt = 1;

		for (int j = i + 1; j < i + 5; j++) {
			if (j >= n)
				break;
			// 수에 중복이 없으므로, 5이내의 차이가 나는 경우 ++
			if (arr[j] - arr[i] < 5) {
				cnt++;
				//cout << arr[j] << " " << arr[i] << endl;
			}
		}

		max_cnt = (max_cnt > cnt) ? max_cnt : cnt;
	}

	if (max_cnt >= 5)
		cout << 0 << "\n";
	else
		cout << 5 - max_cnt << "\n";

	return 0;
}