#include <iostream>
#include <vector>

#define MAX 1001

using namespace std;

int N;
// index: 수열의 index, 1st value: length, 2nd value: prev index
int d[MAX][2];
int arr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		// 길이와 이전 index를 초기화한다.
		d[i][0] = 1;
		d[i][1] = i;
	}

	for (int i = 1; i <= N; i++) {
		int currentValue = arr[i];
		int currentIdx = i;
		for (int j = 0; j < i; j++) {
			int prevValue = arr[j];
			int prevIdx = j;
			// i번째 배열의 원소 이전 원소들을 하나씩 살펴본다.
			if (currentValue > prevValue) {
				// 기존 원소가 가장 큰 값일 때의 최대 길이 증가하는 부분 수열의 길이를 갱신할 수 없는 경우
				if (d[currentIdx][0] > d[prevIdx][0] + 1) {
					continue;
				}
				// 최대 길이를 갱신할 수 있는 경우, 길이와 이전 index를 갱신한다.
				else {
					d[currentIdx][0] = d[prevIdx][0] + 1;
					d[currentIdx][1] = j;
				}
			}
		}
	}

	int maxLength = 0;
	int maxIdx = 1;

	for (int i = 1; i <= N; i++) {
		if (maxLength < d[i][0]) {
			maxLength = d[i][0];
			maxIdx = i;
		}
	}

	vector<int> res;
	while (1) {
		// 자기 자신이 가장 긴 증가하는 부분 수열의 마지막인 경우 종료한다.
		if (maxIdx == d[maxIdx][1])
			break;
		// 부분 수열의 이전 원소로 이동하면서 하나씩 vector에 넣는다.
		res.push_back(arr[maxIdx]);
		maxIdx = d[maxIdx][1];
	}

	cout << maxLength << '\n';

	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}

	return 0;
}