#include <iostream>
#include <algorithm>

#define MAX 100001
#define INF 2147483647

using namespace std;

// (�ּڰ�, �ִ�) ���� �����ϴ� ���׸�Ʈ Ʈ���� ����
pair<int, int> tree[MAX * 4];
int a[MAX];

int init_min(int start, int end, int node) {
	if (start == end) return tree[node].first = a[start];
	int mid = (start + end) / 2;

	return tree[node].first = min(init_min(start, mid, node * 2), init_min(mid + 1, end, node * 2 + 1));
}

int init_max(int start, int end, int node) {
	if (start == end) return tree[node].second = a[start];
	int mid = (start + end) / 2;
	return tree[node].second = max(init_max(start, mid, node * 2), init_max(mid + 1, end, node * 2 + 1));
}

int find_min(int start, int end, int node, int left, int right) {
	// ���� ��
	if (left > end || right < start) return INF;

	// ���� ��
	if (left <= start && end <= right) return tree[node].first;

	// �׷��� ���� ��� (��ģ ���)
	int mid = (start + end) / 2;
	return min(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}

int find_max(int start, int end, int node, int left, int right) {
	// ���� ��
	if (left > end || right < start) return 0;

	// ���� ��
	if (left <= start && end <= right) return tree[node].second;

	// �׷��� ���� ��� (��ģ ���)
	int mid = (start + end) / 2;
	return max(find_max(start, mid, node * 2, left, right), find_max(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	int n, m;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	init_min(0, n - 1, 1);
	init_max(0, n - 1, 1);

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;

		cout << find_min(0, n - 1, 1, start - 1, end - 1) << " " << find_max(0, n - 1, 1, start - 1, end - 1) << "\n";
	}
	return 0;
}

/*
���׸�Ʈ Ʈ��: 
�ڷ� ������ �̿��ؼ� �������� ȿ�������� ���ϴ� ���

�� segment tree�� �ִ�, �ּڰ� �����ϵ��� �����ؼ�
�� ���������� (�ִ�, �ּڰ�) ���� ã�� ���� ������ ��ǥ ����.
*/