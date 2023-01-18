#include <iostream>
#include <algorithm>
#define MAX_ARR 100001
#define MAX 1000000001
using namespace std;

int n, m;
int arr[MAX_ARR];
int tree[2000001];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	//divide current problem to two sub problems recursively (left child + right child)
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

// start ~ end 사이의 노드에서 최솟값을 찾는다.
int findMin(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return MAX; //ouf of the range
	//cout << "current site: " << start << " " << end << endl;
	if (left <= start && end <= right) return tree[node]; //in the range

	int mid = (start + end) / 2;
	// 구간이 겹치는 경우 맞는 경우에서 최솟값을 찾도록 재귀적으로 findMin 함수를 호출한다.
	return min(findMin(start, mid, 2 * node, left, right), findMin(mid + 1, end, 2 * node + 1, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		cout << findMin(0, n - 1, 1, start - 1, end - 1) << "\n";
	}

	return 0;
}