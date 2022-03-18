#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int n;
// ����� ���� ����
vector<int> a[MAX];
int inDegree[MAX], result[MAX];

void topololgySort() {
	queue<int> q;
	// ���� ������ 0�� ��带 queue�� �������ش�.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	// ��Ȯ�� ��� ��带 �湮�ϰ� ������ �Ѵ�.
	for (int i = 1; i <= n; i++) {
		// ��� ��带 �湮���� ���ϰ� ����Ǵ� ��� -> not DAG(directed acycle graph)
		if (q.empty()) return;

		int x = q.front();
		q.pop();
		result[i] = x;		

		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			// ���Ӱ� ���������� 0�̵� ������ queue�� �־��ش�.
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}

	return;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		inDegree[y]++;
	}

	topololgySort();

	return 0;
}