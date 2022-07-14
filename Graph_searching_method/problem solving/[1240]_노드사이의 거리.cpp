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
��� ��尡 ���ڷ� �̾��������� �̿��ؼ� BFS�� ������ �ذ��� �� �־���.

floyd-warshall ������� �׷��� ���� ��� ����� �ּڰ��� ���ؼ� ����ؼ�
������ �ذ��� ���� ������, ��� ��尡 ���ڷ� ����Ǿ��ִ� Ư¡�� ���� �ִ�
�׷��� �󿡼��� ��� Ž���̱� ������, BFS, DFS�� �� ������ Ǯ�̿���.

limits header file�� �߰��ؼ� �پ��� variable type�� INF ���� ����� �� �ִ�.
*/