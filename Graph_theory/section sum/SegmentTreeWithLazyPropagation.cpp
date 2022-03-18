/*
	Date: 2021/11/14
	Brief:
	We can calculate section sum with segment tree with lazy
	propagation.
	Lazy propagation improve update function's running time
	from O(NlgN) to O(lgN).
	Reference:
	https://bowbowbow.tistory.com/4
*/
#include <iostream>
#include <vector>
#define NUMBER 1000001

using namespace std;

typedef struct Tree {
	long long value, lazy;
}Tree;

long long a[NUMBER];
Tree tree[4 * NUMBER];
int n, m, k;

long long init(int start, int end, int node, bool verbose=false) {
	if (start == end) {
		if (verbose)
			cout << "tree[" << node << "] : " << a[start] << "\n";
		return tree[node].value = a[start];
	}
	int mid = (start + end) / 2;
	// divide current problem into two sub problems (left, right childs)
	return tree[node].value = init(start, mid, node * 2, verbose) + init(mid + 1, end, node * 2 + 1, verbose);
}

long long sum(int start, int end, int node, int left, int right) {
	// lazy propagation
	if (tree[node].lazy != 0) {
		tree[node].value += (end - start + 1) * tree[node].lazy;
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	// out of range
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node].value;

	int mid = (start + end) / 2;
	// return the sum of left, right childs
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int left, int right, long long dif, bool verbose=false) {
	// If there is lazy
	if (tree[node].lazy != 0) {
		// update lazy value
		tree[node].value += (end - start + 1) * tree[node].lazy;
		// lazy propagation
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		// free current node's lazy
		tree[node].lazy = 0;
	}

	// out of range
	if (right < start || left > end) return;
	// update current node
	if (left <= start && end <= right) {
		// update the value
		tree[node].value += (end - start + 1) * dif;
		
		if (verbose)
			cout << "tree[" << node << "] -> " << tree[node].value << "\n";

		if (start != end) {
			tree[node * 2].lazy += dif;
			tree[node * 2 + 1].lazy += dif;
		}
		return;
	}

	int mid = (start + end) / 2;
	// update left, right childs
	update(start, mid, node * 2, left, right, dif, verbose);
	update(mid + 1, end, node * 2 + 1, left, right, dif, verbose);
	// update parent node's value
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}

int main() {
	cin.tie(0);
	cin >> n >> m >> k;
	// get the array elements
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		long long d;
		cin >> a;
		switch (a) {
		case 1:
			// update tree
			cin >> b >> c >> d;
			update(1, n, 1, b, c, d);
			break;
		case 2:
			// print section sum
			cin >> b >> c;
			long long res = sum(1, n, 1, b, c);
			cout << res << "\n";
			break;
		}
	}

	return 0;
}