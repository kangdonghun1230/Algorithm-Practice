/*
* @brief Network flow 개념에 대한 간단한 코드
* @date 2021/09/01
* @author 강동훈
* @parameter nothing
* @return print result SCC vector
* @big O O(V + E)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6, result;
// capacity, flow
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

// 최대 유량을 구하는 함수
void maxFlow(int start, int end) {
	while (1) {
		fill(d, d + MAX, -1);
		// traversal graph with BFS method to find start to end paths
		queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				// 방문하지 않은 노드 중에서 용량이 남은 경우 (capacity > flow)
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);	// push to queue
					d[y] = x;	// 경로를 기억합니다.
					if (y == end) break;	// end 지점에 도착한 경우
				}
			}
		}
		if (d[end] == -1) break; // 모든 경로를 찾은 뒤 탈출
		// because we want to find minimum flow
		int flow = INF;

		// 경로를 역추적하며 유량을 탐색합니다.
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		// 앞서 구한 minimum flow 만큼 update flow array
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			// 반대 방향은 마이너스 처리한다.
			f[i][d[i]] -= flow;
		}

		result += flow;
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	printf("%d\n", result);

	return 0;
}