#include <iostream>

using namespace std;

int n, k;

long long countGugudan(long long x) {
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (x / i > n) {
			cnt += n;
		}
		else {
			cnt += (x / i);
		}
	}
	return cnt;
}

// k보다 작으면서 가장 큰 값을 찾아야 한다.
long long binarySearch(long long k) {
	// (1, 1) ~ (n, n) 범위의 값이 x가 될 수 있다.
	long long start = 1;
	// 어차피 k는 최대 n^2이므로
	long long end = k;

	while (start < end) {
		long long mid = (start + end) / 2;

		if (k <= countGugudan(mid)) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	cout << binarySearch(k);

	return 0;
}

/*
배열 전체를 담을 공간은 프로그램 상에서 만들 수 없다.

따라서 배열을 만들지 않고 문제를 해결해야 한다.

** 배열의 특징 **
1. A 배열은 대칭 행렬이다.
2. A 배열의 대각선 상에 위치한 원소들의 값은 제곱수이다.
3. N^2개의 배열의 원소 중에서 K번째로 큰 값을 찾으면 된다.

4. 2차원 배열을 구구단 표처럼 생각해보자.
5. 그러면, 우리가 수의 값을 기준으로 이분 탐색을 진행할 때, 구구단 표를 보면서 해당 값보다 작은 수를 세는 구조가 된다.

*/