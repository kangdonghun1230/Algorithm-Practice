#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;

int n;
// 연결된 간선 정보
vector<int> a[MAX];
int inDegree[MAX];
int cache[MAX], time[MAX];

void topololgySort() {
	queue<int> q;
	// 진입 차수가 0인 노드를 queue에 삽입해준다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			cache[i] = time[i];
			q.push(i);
		}
	}
	// 정확히 모든 노드를 방문하고 끝나야 한다.
	for (int i = 1; i <= n; i++) {
		// 모든 노드를 방문하지 못하고 종료되는 경우 -> not DAG(directed acycle graph)
		if (q.empty()) {
			printf("ddd");
			return;
		}
		int x = q.front();
		q.pop();

		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			// 새롭게 진입차수가 0이된 정점을 queue에 넣어준다.
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