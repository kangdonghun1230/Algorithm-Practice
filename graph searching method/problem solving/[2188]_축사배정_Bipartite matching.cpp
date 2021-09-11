#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int d[MAX];
// ���� Ȯ���� ������� ������ �����ϴ� bool type array
bool c[MAX];
int n, m, num;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int barn = a[x][i];
		if (c[barn]) continue;
		c[barn] = true;

		// ����ִ� ����̰ų�, ������ �����ϰ� �ִ� �Ұ� ��縦 ������ �� �ִٸ�
		if (d[barn] == 0 || dfs(d[barn])) {
			d[barn] = x;
			// matching success
			return true;
		}
	}
	// matching fail
	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			int barn;
			scanf("%d", &barn);
			a[i].push_back(barn);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dfs(i)) cnt++;
		// initialize check array with false every loop execution
		fill(c, c + MAX, false);
	}

	printf("%d\n", cnt);

	return 0;
}