/*
	Date: 2022/08/28
	Brief:
	이분 탐색
	Reference:
	https://st-lab.tistory.com/277
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> homeSite;

int installRouter(int);

// upper bound 양식에 따른 이분 탐색 알고리즘을 구현해야 한다.
// 조건을 만족하는 최댓값을 선택해야 하기 때문이다.
int binarySearch() {
	// lo: 거리의 최솟값, hi: 거리의 최댓값 (1개만 설치하는 경우?)
	int lo = 1, hi = homeSite[n-1] + 1;

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		//cout << lo << " " << hi << endl;
		if (installRouter(mid) < c) {
			// 설치 가능한 공유기 숫자가 적은 경우 거리를 줄여야
			hi = mid;
		}
		else {
			// 설치 가능한 공유기 숫자가 많은 경우 거리를 늘려도 된다.
			lo = mid + 1;
		}

	}
	// hi는 상한선이므로
	return hi - 1;
}

int installRouter(int dis) {
	int cnt = 1;

	int prev = homeSite[0];

	for (int i = 1; i < n; i++) {
		int cur = homeSite[i];
		// 이전에 설치한 공유기 위치가 dis보다 작은 경우 현재 집에는 공유기 설치가
		// 불가능하다.
		if (cur - prev < dis)
			continue;
		// 공유기 설치가 가능한 경우 prev 집 위치를 변경하고, 공유기 수를 count
		prev = cur;
		cnt++;
	}

	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		homeSite.push_back(tmp);
	}
	sort(homeSite.begin(), homeSite.end());
	cout << binarySearch();

	return 0;
}

/*
n개의 집의 좌표가 주어졌을 때, c개의 공유기를 최소의 간격으로 설치할 때
이 간격이 가질 수 있는 최대를 구한다.

* 이분 탐색으로 풀이해야 하는 문제이다.
* 이분 탐색에 대해 기준으로 삼아야 하는 값은 거리이다.
* 거리에 따라 설치 가능한 공유기 대수가 바뀌고
* 설치할 수 있는 공유기 대수에 따라 탐색을 진행해야 되기 때문이다.
* 추가적으로 최대의 거리를 구하는 것이 목표이기 때문에 upper bound 형식으로 이분 탐색을 적용해야 한다고 함.

*/