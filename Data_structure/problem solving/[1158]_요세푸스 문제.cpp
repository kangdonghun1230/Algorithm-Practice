/*
	Date: 2022/07/10
	Brief:

	Reference:
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, k;
	int i;
	queue<int> q;
	vector<int> res;

	cin.tie(NULL);
	cin >> n >> k;

	for (i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (i = 0; i < k - 1; i++) {
			int num = q.front();
			q.pop();
			q.push(num);
		}
		res.push_back(q.front());
		q.pop();
	}

	cout << "<";
	
	for (i = 0; i < n - 1; i++) {
		cout << res[i] << ", ";
	}
	cout << res[n - 1] << ">";

	return 0;
}