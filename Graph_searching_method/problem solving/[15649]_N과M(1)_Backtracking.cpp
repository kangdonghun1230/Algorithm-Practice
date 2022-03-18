/*
	Date: 2022/02/04
	Brief:
	Simple back tracking example
	Reference:
*/
#include <iostream>

#define MAX 9

using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];

void DFS(int num) {
	if (num == m) {
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << " ";
		}

		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[num + 1] = i;
			DFS(num + 1);
			visited[i] = false;
		}
	}

	return;
}

int main() {
	cin.tie(NULL);

	cin >> n >> m;

	DFS(0);
	
	return 0;
}