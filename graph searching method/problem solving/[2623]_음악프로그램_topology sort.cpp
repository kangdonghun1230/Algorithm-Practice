#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, result[MAX];
vector<int> a[MAX];
int inDegree[MAX];

void topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			printf("0\n");
			return;
		}

		int x = q.front();
		q.pop();
		result[i] = x;

		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}

	return;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int num;
		vector<int> b;
		scanf("%d", &num);
		
		for (int j = 0; j < num; j++) {
			int singer;
			scanf("%d", &singer);
			b.push_back(singer);
		}

		for (int j = num - 1; j > 0; j--) {
			a[b[j - 1]].push_back(b[j]);
			inDegree[b[j]]++;
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (auto it = a[i].begin(); it != a[i].end(); it++) {
			cout << *it << " ";
		}cout << endl;
	}*/

	topologySort();

	return 0;
}