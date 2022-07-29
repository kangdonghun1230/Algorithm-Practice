/*
	Date: 2022/07/28
	Brief:
	floyd-warshall
	Reference:
*/
#include <iostream>
#include <vector>

#define MAX 201
#define INF 200001

using namespace std;

int n, m;

int arr[MAX][MAX];
int firstNode[MAX][MAX]; // i -> j로 가는데 처음 방문하는 노드의 정보를 저장

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				arr[i][j] = 0;
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, dis;
		cin >> a >> b >> dis;

		arr[a][b] = dis;
		arr[b][a] = dis;

		firstNode[a][b] = b;
		firstNode[b][a] = a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					// 최단 경로를 갱신하고, 처음 방문해야하는 노드 또한 갱신
					arr[i][j] = arr[i][k] + arr[k][j];
					firstNode[i][j] = firstNode[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else
				cout << firstNode[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}