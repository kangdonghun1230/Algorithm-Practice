/*
* @brief DFS 탐색 방법을 익히기 위한 기본 예제 코드
* @date 2021/08/17
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O
*/
#include <iostream>
#include <vector>

using namespace std;

bool c[8];
vector<int> a[8];

// recursive function의 특성을 이용해 stack 자료구조 없이 DFS를 구현ㄴ
void DFS(int start) {
	// already visited
	if (c[start]) return;
	c[start] = true;
	cout << start << " ";
	for (int i = 0; i < a[start].size(); i++) {
		int y = a[start][i];
		DFS(y);
	}
}
int main() {
	a[1].push_back(2);
	a[1].push_back(3);

	a[2].push_back(1);
	a[2].push_back(3);
	a[2].push_back(4);
	a[2].push_back(5);

	a[3].push_back(1);
	a[3].push_back(2);
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
	DFS(1);

	return 0;
}