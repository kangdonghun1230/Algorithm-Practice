#include <iostream>
#define INF 10000001

using namespace std;

int num = 4;

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// initialize result array
	int d[4][4];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < num; k++) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				// k를 거쳐가는 경우가 더 최단거리인 경우 갱신한다.
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// print result
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}

int main() {
	floydWarshall();

	return 0;
}
/*
Floyd Warshall algorithm : 모든 정점으로 시작하여
그래프 내의 모든 정점으로 향하는 회단 경로의 비용을
계산하는 알고리즘이다.

dynamic programming 기법을 그대로 적용하여
문제를 해결하고 있다.
*/