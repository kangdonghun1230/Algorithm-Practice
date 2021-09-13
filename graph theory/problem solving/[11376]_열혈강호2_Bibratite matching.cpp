#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
// ���� Ȯ���� ������� ������ �����ϴ� bool type array
bool c[MAX];
int n, m, num;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int work = a[x][i];
		// �ش� ������ ���� ó���� �̹� �� ���
		if (c[work]) continue;
		c[work] = true;

		// �ش� ������ ����ڰ� ���ų�, ���� ����ڰ� �ٸ� ������ ���� �� �ִ� ��츦 �ǹ��Ѵ�.
		if (d[work] == 0 || dfs(d[work])) {
			d[work] = x;
			// bipartite matching success
			return true;
		}
	}
	// bipartite matching fail
	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			int work;
			scanf("%d", &work);
			a[i].push_back(work);
		}
	}

	int cnt = 0;
	// �� ���� dfs�� �����ϸ� �ȴ�.
	for (int j = 0; j < 2; j++) {
		for (int i = 1; i <= n; i++) {
			if (dfs(i)) cnt++;
			// initialize check array with false every loop execution
			fill(c, c + MAX, false);
		}
	}

	printf("%d\n", cnt);

	return 0;
}

/*
2���������� �� ������ �� ���� �ϱ��� ó���� �� �ֱ� ������, �� ���� ��
DFS�� �� ���� �������ָ� �˴ϴ�.
*/