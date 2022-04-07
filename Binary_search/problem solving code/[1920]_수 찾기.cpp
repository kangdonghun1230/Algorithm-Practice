/*
	Date: 2022/04/05
	Brief:
	sort + binary search
	or
	���� �ִ��� ���� �Ǵ��ϴ°� �迭�� �����ϴ°� �����ϴ���? -> ���� ����� �ȵɵ�
	Reference:
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

vector<int> arr;
int n, m;

bool binarySearch(int x) {
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] > x) {
			end = mid - 1;
		}
		else if (arr[mid] < x) {
			start = mid + 1;
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	int i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	cin >> m;
	for (i = 0; i < m; i++) {
		int num;
		cin >> num;

		cout << binarySearch(num) << "\n";
	}

	return 0;
}