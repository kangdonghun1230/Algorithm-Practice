#include <iostream>
#include <algorithm>

#define ARR_MAX 100001
#define TREE_MAX 2000001
#define MAX 1000000001
#define endl '\n'

typedef long long ll;

using namespace std;

int N, M;
int arr[ARR_MAX];
int tree[TREE_MAX];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];

	//값이 없는 경우 반으로 쪼개서 반환한다.
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int idx, ll new_value) {
	if (idx < start || end < idx)
		return tree[node];
	else if (start == end) //범위 내에 있으면서 값이 일치 -> 그냥 그 값임을 의미
		return tree[node] = new_value;

	int mid = (start + end) / 2;
	//재귀적인 호출을 통해 현재 노드의 최솟값을 갱신하는 구조이다.
	ll ret = min(update(start, mid, node * 2, idx, new_value), update(mid + 1, end, node * 2 + 1, idx, new_value));
	return tree[node] = ret;
}

int findMin(int start, int end, int node, int left, int right) {
	if (end < left || start > right) return MAX;
	else if (left <= start && end <= right) return tree[node];

	//범위가 걸친 경우는 반으로 쪼갠다.
	int mid = (start + end) / 2;
	return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	//initialize segment tree
	init(1, N, 1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int opt, first, second;
		cin >> opt >> first >> second;

		if (opt == 1) {
			//reinitialization
			arr[first] = second;
			update(1, N, 1, first, second);
		}
		else {
			//find minimum value in the subsequence
			cout << findMin(1, N, 1, first, second) << endl;
		}
	}

	return 0;
}