/*
* @brief 이분매칭 개념에 대한 간단한 코드
* @date 2021/09/05
* @author 강동훈
* @parameter nothing
* @return print result SCC vector
* @big O O(V * E)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
// the number of node, the number of edge
int n = 3, e;

// matching success -> true, matching fail -> false
bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// skip already handled node
		if (c[y])
			continue;
		// c: true -> handled node
		c[y] = true;

		// none matching node or request for change to connected node
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	// matching fail
	return false;
}

int main() {
	//n = 2, e = 3;
	////scanf("%d %d", &n, &e);
	//a[1].push_back(1);
	//a[1].push_back(2);

	//a[2].push_back(1);
	//a[2].push_back(2);
	//
	//a[3].push_back(1);
	//a[3].push_back(2);

	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		// initialize c array with false (at every dfs traversal)
		fill(c, c + MAX, false);
		if (dfs(i)) cnt++;
	}

	printf("%d\n", cnt);

	for (int i = 1; i <= n; i++) {
		printf("%d -> %d\n", d[i], i);
	}

	return 0;
}

/*
기존 네트워클 플로우 알고리즘으로도 해결할 수 있는 문제들 중
2개의 집단으로 나뉘어 있는 경우에 한해서 보다 빠르게 코드를 짤
수 있는 개념입니다.

두 그룹을 최대한 매칭 시키는 것을 목표로 하는 알고리즘이고, 이를
'최대 매칠'을 목표로 한다고 합니다. 이 개념을 플로우 개념으로 생각
하면 네트워크 플로우와 정확히 일치하게 됩니다.

기존에 사용한 네트워크 플로우 알고리즘인 에드몬드 카프 알고리즘의
시간 복잡도는 O(V * E ^ 2)였습니다.
이분매칭에 한해 이것보다 더 빠르고 효율적인 알고리즘을 설게할 수 있는데,
바로 DFS를 이용하면 됩니다. 

-----------------------------------------------

(BFS, DFS가 크게 의미 없는 것 같다. 왜냐하면 어차피 탐색을 하는 경로의 길이가
1인 것이 고정이기 때문에 BFS, DFS 어느 방식으로 탐색한다고 말하는 것이 애매하다고
생각한다.)

-----------------------------------------------

이 방법으로 네트워크 플로우의 문제를 해결할시 시간복잡도를 O(V + E)까지 단축할 수 있습니다.
(모든 노드가 자신과 연결된 간선의 수만큼만 최대로 탐색을 진행하기 때문)

가장 빠른 속도는 아니지만, 가장 간단하고 쉽게 구현할 수 있다는 점에서 가장 많이 사용하는
알고리즘이라고 합니다.
*/