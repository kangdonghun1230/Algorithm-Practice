#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
// 현재 확인한 노드인지 정보를 저장하는 bool type array
bool c[MAX];
int n, m, num, k;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int work = a[x][i];
		// 해당 업무에 대한 처리를 이미 한 경우
		if (c[work]) continue;
		c[work] = true;

		// 해당 업무의 담당자가 없거나, 기존 담당자가 다른 업무를 맡을 수 있는 경우를 의미한다.
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
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			int work;
			scanf("%d", &work);
			a[i].push_back(work);
		}
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (dfs(i)) cnt++;
		// initialize check array with false every loop execution
		fill(c, c + MAX, false);
	}

	int extra = 0;
	for (int i = 1; i <= n && extra < k; i++) {
		if (dfs(i)) {
			cnt++; extra++;
		}
		fill(c, c + MAX, false);
	}

	printf("%d\n", cnt);

	return 0;
}

/*
3문제에서는 각 직원이 두 개의 일까지 처리할 수 있기 때문에, k번 매칭이
될 때까지만 2번째 dfs를 시행하면 됩니다. (k명의 직원만 두가지 일을 
담당할 수 있기 때문입니다.)
*/