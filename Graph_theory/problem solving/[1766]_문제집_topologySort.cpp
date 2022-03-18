#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

// vector to save edge information
vector<int> a[MAX];
// integer array to save indegree information
int inDegree[MAX];
int n, m;

void topologySort() {
	// result array
	int result[MAX];
	// queue structure for topology sorting
	priority_queue<int> pq;

	// push the node to queue whose indegree is 0
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) pq.push(-i);
	}

	for (int i = 1; i <= n; i++) {
		if (pq.empty()) {
			return;
		}
		// pop the node from queue
		int cur = -pq.top();
		pq.pop();
		// save the node's order in result array
		result[i] = cur;

		for (int j = 0; j < a[cur].size(); j++) {
			int next = a[cur][j];
			if (--inDegree[next] == 0) {
				pq.push(-next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}printf("\n");
	return;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		a[x].push_back(y);
		// y's indegree number + 1
		inDegree[y]++;
	}

	topologySort();

	return 0;
}

/*
priority queue�� �̿��Ͽ� ������������ queue�ȿ� ����ִ�
������ �����ϸ� �����ؾ� �Ѵ�. �ֳ��ϸ�, ���̵��� ���� ������
�켱���� Ǯ����Ѵٴ� ������ �ֱ� �����̴�.
*/