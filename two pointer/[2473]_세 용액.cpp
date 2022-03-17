/*
	Date: 2022/03/17
	Brief:
	two pointer algorithm.
	Reference:
*/
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 5001

using namespace std;

long long arr[MAX];

int main() {
	int N;
	int i;
	long long dif = LLONG_MAX;
	int p1, p2, p3;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (i = 0; i < N - 1; i++) {
		int start = i + 1;
		int end = N - 1;
		long long sum = arr[i] + arr[start] + arr[end];

		while (start < end) {
			if (dif > abs(sum)) {
				dif = abs(sum);
				p1 = i, p2 = start, p3 = end;
			}
			if (sum > 0) {
				sum -= arr[end--];
				sum += arr[end];
			}
			else if (sum == 0) {
				p1 = i, p2 = start, p3 = end;
				break;
			}
			else {
				sum -= arr[start++];
				sum += arr[start];
			}
		}
	}

	cout << arr[p1] << " " << arr[p2] << " " << arr[p3] << "\n";

	return 0;
}