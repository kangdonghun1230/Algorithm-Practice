/*
* @brief topology sort(위상 정렬) 간단한 예시 코드
* @date 2021/08/30
* @author 강동훈
* @parameter nothing
* @return print result array
* @big O O(V + E)
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

// inDegree : 진입차수 information
// n : the number of nodes
int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	// 진입 차수 0인 node, queue에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// 위상 정렬이 완전히 수행되려면 N개의 노드를 방문했어야 한다.
	for (int i = 1; i <= n; i++) {
		// 모든 노드를 방문하지않고 탐색이 종료되는 경우 -> 사이클 발생을 의미
		if (q.empty()) {
			printf("사이클 발생\n");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}

int main() {
	n = 7;

	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;

	a[2].push_back(3);
	inDegree[3]++;

	a[3].push_back(4);
	inDegree[4]++;

	a[4].push_back(6);
	inDegree[6]++;

	a[5].push_back(6);
	inDegree[6]++;

	a[6].push_back(7);
	inDegree[7]++;

	topologySort();

	return 0;
}

/*
topology sort(위상 정렬)은 '순서가 정해져있는 작업'을
수행할 때 그 순서를 결정하기 위해 사용하는 algorithm입니다.

성공적으로 목적지에만 도달하면 되기 떄문에, 구해낸 답 말고도
여러 개의 답이 존재할 수 있습니다.

또한 위상 정령은 DAG(Directed Acyclic Graph)에만 적용 가능합니다.
이는 cycle이 발생하지 않는 그래프를 의미합니다. 
(cycle이 발생하는 경우 위상 정렬은 불가능합니다.)

구현 순서:
1. 진입 차수가 0인 정점을 큐에 삽입한다.
2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거한다.
3. 간선 제거 후 진입차수가 0이 된 정점을 큐에 삽입
4. 큐가 빌 때까지 2 ~ 3번 과정을 반복. 모든 원소를 방문하기 전에
큐가 비어있다면 -> 사이클이 존재하는 것, 모든 원소를 방문했다면 -> 큐에서
꺼내는 순서가 위상 정렬의 결과이다.
*/