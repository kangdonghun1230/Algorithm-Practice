#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

vector<int> a[MAX];
int inDegree[MAX];
int delay[MAX];
int cache[MAX];
int n;

void topologySort() {
	int result_time = 0;
	
	queue<int> q;

	// push the node to priority queue whose indegree is 0
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			cache[i] = delay[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		// if pq is empty before visiting whole nodes
		if (q.empty()) return;

		int cur = q.front();
		q.pop();

		for (int j = 0; j < a[cur].size(); j++) {
			int next = a[cur][j];
			if (--inDegree[next] == 0) {
				q.push(next);
			}
			// 진입 차수가 0이 되지 않았더라도 next 작업이 걸리는 시간을
			// 미리 update 해준다. (최대값으로)
			cache[next] = max(cache[next], cache[cur] + delay[next]);
		}
	}

	for (int i = 1; i <= n; i++) {
		result_time = max(result_time, cache[i]);
	}

	printf("%d\n", result_time);

	return;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int time, num;
		scanf("%d %d", &time, &num);

		delay[i] = time;

		for (int j = 0; j < num; j++) {
			int next;
			scanf("%d", &next);

			a[next].push_back(i);
			inDegree[i]++;
		}
	}

	topologySort();

	return 0;
}