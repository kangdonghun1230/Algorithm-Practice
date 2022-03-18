/*
	Date: 2021/11/14
	Brief:
	Segment Tree is the structure get the sum
	of particular section in tree array
	Reference: https://blog.naver.com/ndb796/221282210534
*/
#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

// array size N보다 큰 2의 거듭제곱 중 가장 작은 것의 2배 크기면 tree의 범위를 커버할 수 있다.
int a[] = { 1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5 };
int tree[4 * NUMBER]; // 현재 예제에서는 전체 element 개수에 4배 만큼이면 모든 범위를 커버할 수 있습니다.

// initialize tree array (tree structure which have the whole section sum informations)
int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	// divide current to two sub problems (left child + right child)
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
/*
	function name: sum
	brief:
	Get the section sum of start ~ end
	left, right mean the range of section which we want to
	get the sum of this area
*/
int sum(int start, int end, int node, int left, int right) {
	// out of range
	if (left > end || right < start) return 0;
	// in the range, tree[node]'s value means the section sum of current left ~ right
	if (left <= start && right >= end) return tree[node];
	// if not divide current problem into two sub problems
	int mid = (start + end) / 2;
	// left child + right child
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
/*
	function name: update
	brief:
	update the tree with new element value
*/
void update(int start, int end, int node, int idx, int dif) {
	// out of range
	if (idx < start || idx > end) return;
	// In the range: initialize other nodes sliding down
	tree[node] += dif;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, node * 2 + 1, idx, dif);
}

int main() {
	// except for SectionSum tree start from index 0 (SectionSum tree start from index 1)
	// SectionSum tree initialization	
	init(0, NUMBER - 1, 1);

	// get the section sum of 0 ~ 12 elements
	cout << "section sum of 0 ~ 12: " << sum(0, NUMBER - 1, 1, 0, 12) << "\n";
	// get the section sum of 3 ~ 8 elements
	cout << "section sum of 3 ~ 8: " << sum(0, NUMBER - 1, 1, 3, 8) << "\n";
	// update the section sum information
	cout << "update element5 -= 5\n";
	update(0, NUMBER - 1, 1, 5, -5); // start, end, node, idx, dif
	// get the same section sum after update
	cout << "3부터 8까지의 합은: " << sum(0, NUMBER - 1, 1, 3, 8) << "\n";

	return 0;
}

/*
left, right를 이용하여 구하고 싶은 범위를 표현하고
start, end를 이용하여 array의 시작과 끝의 범위를 표현합니다.
마지막으로 node를 이용하여 tree array를 탐색하며 원하는 범위의 합에 대한 index를 찾아간다.
*/