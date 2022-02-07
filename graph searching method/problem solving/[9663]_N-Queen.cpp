/*
	Date: 2022/02/07
	Brief:
	simple back tracking algorithm problem.
	Reference:
*/
#include <iostream>
#include <cstdlib>
#define MAX 16

using namespace std;

int n, res;
int visited[MAX];

bool checkingPromising(int idx) {
	for (int i = 1; i < idx; i++) {
		if (visited[i] == visited[idx])
			return false;
		else if (abs(visited[i] - visited[idx]) == idx - i)
			return false;
	}
	return true;
}

void backTracking(int x) {
	int i;
	if (x == n + 1) {
		res++;
		return;
	}

	// Checking the promising status of current case.
	for (i = 1; i <= n; i++) {
		visited[x] = i;
		if (checkingPromising(x)) {
			backTracking(x + 1);
		}
	}
	// This case is not promising any more.
	return;
}

int main() {
	cin.tie(NULL);
	cin >> n;

	backTracking(1);

	cout << res << "\n";

	return 0;
}