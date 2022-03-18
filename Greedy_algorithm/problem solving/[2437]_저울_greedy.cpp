#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int w[MAX];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	sort(w, w + n);

	int min_weight = 1;
	for (int i = 0; i < n; i++) {
		if (w[i] > min_weight) break;
		min_weight += w[i];
	}

	cout << min_weight << endl;

	return 0;
}

/*
��ȭ���� ���� ��������� �˰ڴµ�
���ʿ� ������ ���� ��ȭ���� �ǹ��ϴ� �ٰ�
������ ������ �������� ���ϰڴ�.

���� ������ �����ϴ� ��� min_weight������ ��� ������
���� �߸� ������ ����� �� �� �ִ� ������ �𸣰ڴ�.

�ٽ� �����ĵ� ����μ��� �� Ǯ �����̴�.
*/