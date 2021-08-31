/*
* @brief SCC(strongly connected component) 간단한 예시 코드
* @date 2021/08/31
* @author 강동훈
* @parameter nothing
* @return print result SCC vector
* @big O O(V + E)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

// DFS는 총 정점의 개수만큼 실행된다.
int DFS(int x) {
	d[x] = ++id;
	s.push(x); // stack에 자기 자신을 삽입한다.

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// 방문하지 않은 이웃
		if (d[y] == 0) parent = min(parent, DFS(y));
		// 처리중인 이웃
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	// 부모 노드가 자기 자신인 경우
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	// 자신의 부모 값을 리턴합니다.
	return parent;
}

int main() {
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	// 결론적으로 모든 노드에 대해서 한 번씩만 DFS를 실행하게 된다.
	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) DFS(i);
	}

	printf("SCC의 개수 : %d\n", SCC.size());

	for (int i = 0; i < SCC.size(); i++) {
		printf("%d번째 SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*
서로 방문이 가능한 노드들에 대해서 SCC 안에 속한다고 할 수 있다.

방향 그래프의 경우 사이클이 형성되면 SCC에 해당한다고 할 수 있고
무향 그래프의 경우에는 그 그래프 전체가 SCC에 해당합니다.

따라서 방향 그래프일 때만 SCC가 의미가 있다.

SCC를 추출하는 대표적인 알고리즘은 타잔 알고리즘(Tarjan's algorithm)을
알아보도록 하겠습니다.

타잔 알고리즘 : 모든 정점에 대해서 DFS를 실시하여 SCC를 찾는 알고리즘이다.
DFS로 탐색하는 경우 부모로 돌아올 수 있어야 SCC가 성립할 수 있다.

전체 그래프에서 SCC를 추출하게 되면 각 SCC를 하나의 노드로 보았을 때 DAG가
형성되기 때문에 이를 위상 정렬을 수행할 수 있다.
*/