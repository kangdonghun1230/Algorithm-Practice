/*
* @brief BFS 탐색 방법을 익히기 위한 기본 예제 코드
* @date 2021/08/17
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int num = 7;
bool c[7];
vector<int> a[8];

void BFS(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main() {
	a[1].push_back(2);
	a[1].push_back(3);

	a[2].push_back(1);
	a[2].push_back(4);
	a[2].push_back(5);

	a[3].push_back(1);
	a[3].push_back(6);
	a[3].push_back(7);

	a[4].push_back(2);
	a[4].push_back(5);

	a[5].push_back(2);
	a[5].push_back(4);

	a[6].push_back(3);
	a[6].push_back(7);

	a[7].push_back(3);
	a[7].push_back(6);
	// start from 1(start node)
	BFS(1);
	return 0;
}