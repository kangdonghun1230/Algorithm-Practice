#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;

int n;
// ����� ���� ����
vector<int> a[MAX];
int inDegree[MAX];
int cache[MAX], time[MAX];

void topololgySort() {
	queue<int> q;
	// ���� ������ 0�� ��带 queue�� �������ش�.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			cache[i] = time[i];
			q.push(i);
		}
	}
	// ��Ȯ�� ��� ��带 �湮�ϰ� ������ �Ѵ�.
	for (int i = 1; i <= n; i++) {
		// ��� ��带 �湮���� ���ϰ� ����Ǵ� ��� -> not DAG(directed acycle graph)
		if (q.empty()) {
			printf("ddd");
			return;
		}
		int x = q.front();
		q.pop();

		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			// ���Ӱ� ���������� 0�̵� ������ queue�� �־��ش�.
			if (--inDegree[y] == 0) {
				q.push(y);
			}
			cache[y] = max(cache[x] + time[y], cache[y]);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", cache[i]);
	}

	return;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		// get time info
		scanf("%d", &time[i]);

		while (1) {
			// get adjacent node info
			int x;
			scanf("%d", &x);

			if (x == -1) break;
			a[x].push_back(i);
			inDegree[i]++;
		}
	}

	topololgySort();

	return 0;
}