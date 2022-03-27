/*
	Date: 2022/03/27
	Brief:
	find path with floyd-warshall
	Reference:
	https://blog.naver.com/ndb796/221234427842
*/
#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int arr[MAX][MAX];

int main() {
	int n;
	int i, j, k;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			// i: start node
			for (j = 0; j < n; j++) {
				// j: end node
				if (arr[i][k] == 1 && arr[k][j] == 1)
					arr[i][j] = 1;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}