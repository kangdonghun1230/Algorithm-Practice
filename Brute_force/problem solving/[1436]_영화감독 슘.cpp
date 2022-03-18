/*
	Date: 2022/02/19
	Brief:
	simple brute force problem
	Reference:
*/
#include <iostream>
#define MAX 10001

using namespace std;

int arr[MAX];

bool check(int x) {
	int cnt = 0;
	int num;
	while (1) {
		num = x % 10;
		x /= 10;
		if (num == 6) {
			cnt++;
			if (cnt == 3) {
				return true;
			}
		}
		else {
			cnt = 0;
		}
		if (x == 0) break;
	}

	return false;
}

int main() {
	int n, cnt = 0;
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; ; i++) {
		if (check(i)) {
			arr[cnt++] = i;
		}
		if (cnt == 10000) break;
	}
	cout << arr[n - 1] << "\n";

	return 0;
}

/*
	규칙이 뒤죽박죽이여서 그냥
	가장 작은 수부터 확인하면서 666에 대한
	pattern matching이 가능한 프로그램을 구현해야
	될 것 같다는 생각이 듬. (brute force 방식으로)
*/