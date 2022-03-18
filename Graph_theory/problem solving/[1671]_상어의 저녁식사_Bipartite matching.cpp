#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int status[MAX][3];
int d[MAX];
// 현재 확인한 노드인지 정보를 저장하는 bool type array
bool c[MAX];
int n;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;

		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		status[i][0] = a; status[i][1] = b; status[i][2] = c;
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (status[i][0] >= status[j][0] && status[i][1] >= status[j][1] && status[i][2] >= status[j][2]) {
				a[i].push_back(j);
			}
			else if (status[i][0] <= status[j][0] && status[i][1] <= status[j][1] && status[i][2] <= status[j][2]) {
				a[j].push_back(i);
			}
		}
	}

	int cnt = 0;
	for (int num = 0; num < 2; num++) {
		for (int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if (dfs(i)) cnt++;
		}
	}
	printf("%d\n", n - cnt);
}

/*
이 문제는 매칭이 되는 상어에 대해서 조건을 기반으로 따로 정해줘야 하는
문제입니다.
*/