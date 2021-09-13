#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int n;
// 연결된 간선 정보
vector<int> a[MAX];
int inDegree[MAX], result[MAX];

void topololgySort() {
	queue<int> q;
	// 진입 차수가 0인 노드를 queue에 삽입해준다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	// 정확히 모든 노드를 방문하고 끝나야 한다.
	for (int i = 1; i <= n; i++) {
		// 모든 노드를 방문하지 못하고 종료되는 경우 -> not DAG(directed acycle graph)
		if (q.empty()) return;

		int x = q.front();
		q.pop();
		result[i] = x;		

		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			// 새롭게 진입차수가 0이된 정점을 queue에 넣어준다.
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