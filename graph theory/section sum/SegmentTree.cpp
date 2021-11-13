#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

// array size N보다 큰 2의 거듭제곱 중 가장 작은 것의 2배 크기면 tree의 범위를 커버할 수 있다.
int a[] = { 1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5 };
int tree[4 * NUMBER]; // 현재 예제에서는 전체 element 개수에 4배 만큼이면 모든 범위를 커버할 수 있습니다.

// initialize tree array (모든 범위에 대한 합을 가지는 tree structure)
int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	// 재귀적으로 두 부분으로 나눈 후 그 합을 자시 자신으로 한다.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	// 범위 밖
	if (left > end || right < start) return 0;
	// 범위 내
	if (left <= start && right >= end) return tree[node];
	// 그렇지 않다면 두 부분으로 나누어 합을 구하기
	int mid = (start + end) / 2;
	// left child + right child
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, int dif) {
	// 범위 밖
	if (idx < start || idx > end) return;
	// 범위 내면 내려가면서 다른 원소도 갱신해준다.
	tree[node] += dif;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, node * 2 + 1, idx, dif);
}

int main() {
	// 구간 합 트리의 인텍스를 제외하고는 모두 인덱스 0부터 시작합니다. (구간 합 트리는 1부터)
	// 구간 합 트리 initialization	
	init(0, NUMBER - 1, 1);

	// 구간 합 구하기
	cout << "0부터 12까지의 합은: " << sum(0, NUMBER - 1, 1, 0, 12) << "\n";
	// 구간 합 구하기
	cout << "3부터 8까지의 합은: " << sum(0, NUMBER - 1, 1, 3, 8) << "\n";
	// 구간 합 갱신하기
	cout << "index 5의 원소를 -5만큼 수정\n";
	update(0, NUMBER - 1, 1, 5, -5); // start, end, node, idx, dif
	
	// 갱신 후의 구간 합 구하기
	cout << "3부터 8까지의 합은: " << sum(0, NUMBER - 1, 1, 3, 8) << "\n";

	return 0;
}

/*
left, right를 이용하여 구하고 싶은 범위를 표현하고
start, end를 이용하여 array의 시작과 끝의 범위를 표현합니다.
마지막으로 node를 이용하여 tree array를 탐색하며 원하는 범위의 합에 대한 index를 찾아간다.
*/