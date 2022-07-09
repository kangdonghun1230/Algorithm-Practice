/*
	Date: 2022/07/09
	Brief:
	sorting algorithm
	Reference:
*/
#include <iostream>
#include <algorithm>

#define MAX 51

using namespace std;

int n;
int arr1[MAX], arr2[MAX];
int idx[MAX];
bool visited[MAX];

int main() {
	int i, j;

	cin.tie(NULL);
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr1[i];
		arr2[i] = arr1[i];
	}

	sort(arr1, arr1 + n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if ((arr2[i] == arr1[j]) && !visited[j]) {
				idx[i] = j;
				visited[j] = true;
				break;
			}
		}
	}

	for (i = 0; i < n; i++) {
		cout << idx[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
이분 탐색으로 탐색 방식을 전환하면 더 빠르게 문제 해결이 가능하다.
*/