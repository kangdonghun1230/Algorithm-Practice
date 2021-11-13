#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

// array size N���� ū 2�� �ŵ����� �� ���� ���� ���� 2�� ũ��� tree�� ������ Ŀ���� �� �ִ�.
int a[] = { 1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5 };
int tree[4 * NUMBER]; // ���� ���������� ��ü element ������ 4�� ��ŭ�̸� ��� ������ Ŀ���� �� �ֽ��ϴ�.

// initialize tree array (��� ������ ���� ���� ������ tree structure)
int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	// ��������� �� �κ����� ���� �� �� ���� �ڽ� �ڽ����� �Ѵ�.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	// ���� ��
	if (left > end || right < start) return 0;
	// ���� ��
	if (left <= start && right >= end) return tree[node];
	// �׷��� �ʴٸ� �� �κ����� ������ ���� ���ϱ�
	int mid = (start + end) / 2;
	// left child + right child
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, int dif) {
	// ���� ��
	if (idx < start || idx > end) return;
	// ���� ���� �������鼭 �ٸ� ���ҵ� �������ش�.
	tree[node] += dif;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, node * 2 + 1, idx, dif);
}

int main() {
	// ���� �� Ʈ���� ���ؽ��� �����ϰ�� ��� �ε��� 0���� �����մϴ�. (���� �� Ʈ���� 1����)
	// ���� �� Ʈ�� initialization	
	init(0, NUMBER - 1, 1);

	// ���� �� ���ϱ�
	cout << "0���� 12������ ����: " << sum(0, NUMBER - 1, 1, 0, 12) << "\n";
	// ���� �� ���ϱ�
	cout << "3���� 8������ ����: " << sum(0, NUMBER - 1, 1, 3, 8) << "\n";
	// ���� �� �����ϱ�
	cout << "index 5�� ���Ҹ� -5��ŭ ����\n";
	update(0, NUMBER - 1, 1, 5, -5); // start, end, node, idx, dif
	
	// ���� ���� ���� �� ���ϱ�
	cout << "3���� 8������ ����: " << sum(0, NUMBER - 1, 1, 3, 8) << "\n";

	return 0;
}

/*
left, right�� �̿��Ͽ� ���ϰ� ���� ������ ǥ���ϰ�
start, end�� �̿��Ͽ� array�� ���۰� ���� ������ ǥ���մϴ�.
���������� node�� �̿��Ͽ� tree array�� Ž���ϸ� ���ϴ� ������ �տ� ���� index�� ã�ư���.
*/