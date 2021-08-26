#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number = 6;
int INF = 100000000;

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2 ,3 ,0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

// check visited or not
bool v[6];
// shortest distance
int d[6];

// 현재 상태에서 최소 거리를 갖는 정점을 반환하는 함수
int shortestIndex() {
	int min = INF;
	int idx = 0;

	/*
	선형탐색 : 앞에서부터 하나씩 탐색한다.
	*/
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			idx = i;
		}
	}

	return idx;
}

// dijkstra
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}

	// start node : visited
	v[start] = true;

	// i index를 사용하지 않고 단순 반복횟수를 의미하며, 총 노드 개수 - 2번만 반복하면 되기 때문이다.
	for (int i = 0; i < number - 2; i++) {
		// 가장 가까운 노드 방문처리
		int cur = shortestIndex();
		v[cur] = true;
		for (int j = 0; j < number; j++) {
			if (!v[j]) {
				if (d[cur] + a[cur][j] < d[j]) {
					d[j] = d[cur] + a[cur][j];
				}
			}
		}
	}

}

int main() {
	dijkstra(0);

	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}

	return 0;
}

/*
dijkstra : 현재까지 알고있던 최단 경로를 갱신해 나아가는 알고리즘

다익스트라 알고리즘은 다이나믹 프로그래밍 또는 그리디 알고리즘으로 분류된다.

dp : 최단 거리는 여러 개의 최단 거리로 이루어져있기 때문
greedy : 간선의 길이를 정렬하여 가장 짧은 것부터 선택하여 사용하기 때문

dijkstra 작동 과정`
1. 출발 노드를 설정한다.
2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장한다.
3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택한다.
4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신한다.
5. 위 과정에서 3 ~ 4번을 반복한다.
*/