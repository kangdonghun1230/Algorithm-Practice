/*
	Date: 2022/07/18
	Brief:
	Segment tree: Ư�� ������ ���� ������ ���ϱ� ���� ����ϴ� �ڷᱸ��
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

	// ��������� �� �κ����� ������ �� ���� �ڱ� �ڽ��� ������ �մϴ�.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start: ���� �ε���, end: �� �ε���
// left, right: ���� ���� ���ϰ��� �ϴ� ������ �ǹ�
long long sum(int start, int end, int node, int left, int right) {
	// ���� �ۿ� �ִ� ���
	if (end < left || right < start) {
		return 0;
	}
	// ���� �ȿ� �ִ� ���
	if (left <= start && end <= right) {
		return tree[node];
	}
	// �׷��� ���� ��� �� �κ����� ����� ���� ���Ѵ�. (������ ��ġ�� ���)
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start: ���� �ε���, end: �� �ε���
// index: ���� ���� �����ϰ��� �ϴ� ����� �ε���
// dif: ������ ��
void update(int start, int end, int node, int index, long long dif) {
	// ���� �ۿ� �ִ� ���
	if (index < start || end < index) return;
	// ���� �ȿ� �ִ� ��� update
	tree[node] += dif;

	if (start == end) {
		arr[index] += dif;
		return;
	}

	int mid = (start + end) / 2;
	// �Ʒ��� �������鼭 update ���ش�.
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
	// ���� �� Ʈ�� �����ϱ�
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