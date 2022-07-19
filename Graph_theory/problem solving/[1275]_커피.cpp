/*
	Date: 2022/07/18
	Brief:
	Segment tree: 특정 구간의 합을 빠르게 구하기 위해 사용하는 자료구조
	Reference:
*/
#include <iostream>
#define MAX 100001

using namespace std;

long long arr[MAX];
long long tree[MAX * 4];

long long init(int start, int end, int node) {
	if (start == end) 
		return tree[node] = arr[start];
	int mid = (start + end) / 2;

	// 재귀적으로 두 부분으로 나누고 그 합을 자기 자신의 값으로 합니다.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start: 시작 인덱스, end: 끝 인덱스
// left, right: 구간 합을 구하고자 하는 범위를 의미
long long sum(int start, int end, int node, int left, int right) {
	// 범위 밖에 있는 경우
	if (end < left || right < start) {
		return 0;
	}
	// 범위 안에 있는 경우
	if (left <= start && end <= right) {
		return tree[node];
	}
	// 그렇지 않은 경우 두 부분으로 나누어서 합을 구한다. (범위가 겹치는 경우)
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start: 시작 인덱스, end: 끝 인덱스
// index: 구간 합을 수정하고자 하는 노드의 인덱스
// dif: 수정할 값
void update(int start, int end, int node, int index, long long dif) {
	// 범위 밖에 있는 경우
	if (index < start || end < index) return;
	// 범위 안에 있는 경우 update
	tree[node] += dif;

	if (start == end) {
		arr[index] += dif;
		return;
	}

	int mid = (start + end) / 2;
	// 아래로 내려가면서 update 해준다.
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
	int n, q;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	// 구간 합 트리 생성하기
	init(1, n, 1);

	for (int i = 0; i < q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		long long dif = b - arr[a];
		cout << sum(1, n, 1, x, y) << "\n";
		update(1, n, 1, a, dif);
	}

	return 0;
}