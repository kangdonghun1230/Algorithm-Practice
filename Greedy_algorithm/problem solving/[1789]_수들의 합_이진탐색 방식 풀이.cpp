#include <iostream>
#include <cmath>

using namespace std;

//int main() {
//	long s;
//	cin >> s;
//	// x는 2 * s의 제곱근
//	// 대략 x (x + 1) / 2의 제곱근을 구해야하기 때문이다.
//	long x = sqrt(2 * s);
//	long cnt = 0;
//	for (long i = x; i > 0; i--) {
//		// 등차수열의 합을 구하는 방식으로 최대 개수를 구한다.
//		if ((i * i + i) / 2 <= s) {
//			cnt = i;
//			break;
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}

int main() {
	long s;
	cin >> s;

	long cnt;
	long start = 1, end = s;
	// 위의 방식을 그대로 참고하되 이분 탐색 방식으로
	// sqrt의 결과를 구한다고 생각하면 된다.
	while (start <= end) {
		long mid = (start + end) / 2;
		if (mid * (mid + 1) / 2 <= s) {
			cnt = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << cnt << endl;
	return 0;
}