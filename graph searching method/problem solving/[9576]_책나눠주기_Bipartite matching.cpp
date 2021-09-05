/*
* @brief �̺и�Ī ���信 ���� ������ �ڵ�
* @date 2021/09/05
* @author ������
* @parameter nothing
* @return print result SCC vector
* @big O O(V * E)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
// the number of node, the number of members(�������б� �кλ�)
int n = 3, m;

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
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);

		int cnt = 0;

		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			
			//�Ʒ� �κ��� �߸� �����Ͽ� ������ Ʋ�Ⱦ���
			for (int j = x; j <= y; j++) {
				a[i].push_back(j);
			}
		}

		for (int i = 1; i <= m; i++) {
			// initialize c array with false (at every dfs traversal)
			fill(c, c + MAX, false);
			if (dfs(i)) cnt++;
		}

		printf("%d\n", cnt);

		for (int i = 1; i <= m; i++) {
			a[i].clear();
		}
		fill(d, d + MAX, 0);
	}
	return 0;
}
