/*
	Date: 2022/04/01
	Brief:
	math? sort
	Reference:
	just sort array and calculate the multiple of first and last number
*/
#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

int arr[MAX];

int main() {
	int num;
	int i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;

	int res = 1;
	for (i = 0; i < num; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + num);

	res = arr[0] * arr[num - 1];

	cout << res << "\n";

	return 0;
}