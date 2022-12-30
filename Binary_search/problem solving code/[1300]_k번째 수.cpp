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

// k���� �����鼭 ���� ū ���� ã�ƾ� �Ѵ�.
long long binarySearch(long long k) {
	// (1, 1) ~ (n, n) ������ ���� x�� �� �� �ִ�.
	long long start = 1;
	// ������ k�� �ִ� n^2�̹Ƿ�
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
�迭 ��ü�� ���� ������ ���α׷� �󿡼� ���� �� ����.

���� �迭�� ������ �ʰ� ������ �ذ��ؾ� �Ѵ�.

** �迭�� Ư¡ **
1. A �迭�� ��Ī ����̴�.
2. A �迭�� �밢�� �� ��ġ�� ���ҵ��� ���� �������̴�.
3. N^2���� �迭�� ���� �߿��� K��°�� ū ���� ã���� �ȴ�.

4. 2���� �迭�� ������ ǥó�� �����غ���.
5. �׷���, �츮�� ���� ���� �������� �̺� Ž���� ������ ��, ������ ǥ�� ���鼭 �ش� ������ ���� ���� ���� ������ �ȴ�.

*/