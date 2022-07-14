/*
	Date: 2022/07/14
	Brief:
	BFS / DFS, graph searching
	Reference:
*/
#include <iostream>
#include <limits>
#include <vector>
#include <queue>

#define MAX 10001

using namespace std;

vector<pair<int, int>> map[MAX];

int n, m;

int BFS(int sta, int end) {
	queue<pair<int, int>> q;
	bool visited[MAX] = {0, };

	q.push({ sta, 0 });
	int dis = 0;
	visited[sta] = true;

	while (1) {
		int cur_des = q.front().first;
		int cur_dis = q.front().second;
		q.pop();

		//cout << cur_des << " " << cur_dis << endl;

		if (cur_des == end) {
			dis = cur_dis;
			break;
		}

		for (int i = 0; i < map[cur_des].size(); i++) {
			int next_des = map[cur_des][i].first;
			int next_dis = map[cur_des][i].second + cur_dis;

			if (visited[next_des])
				continue;

			// push next point to queue
			q.push({ next_des, next_dis });
			visited[next_des] = true;
		}
	}
	return dis;
}

int main() {
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int sta, end, dis;

		cin >> sta >> end >> dis;

		map[sta].push_back({ end, dis });
		map[end].push_back({ sta, dis });
	}

	for (int i = 0; i < m; i++) {
		int sta, end;
		cin >> sta >> end;

		cout << BFS(sta, end) << "\n";
	}

	return 0;
}

/*
모든 노드가 일자로 이어져있음을 이용해서 BFS로 문제를 해결할 수 있었다.

floyd-warshall 방식으로 그래프 내의 모든 경로의 최솟값에 대해서 계산해서
문제를 해결할 수도 있으나, 모든 노드가 일자로 연결되어있는 특징을 갖고 있는
그래프 상에서의 경로 탐색이기 때문에, BFS, DFS가 더 적합한 풀이였다.

limits header file을 추가해서 다양한 variable type의 INF 값을 사용할 수 있다.
*/