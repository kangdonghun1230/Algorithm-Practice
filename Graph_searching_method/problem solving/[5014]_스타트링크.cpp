#include <iostream>
#include <queue>

#define MAX 1000001

using namespace std;

bool visited[MAX];
int step[MAX];
int f, s, g, u, d;

bool inRange(int x) {
	return (1 <= x && x <= f);
}

void bfs(int x) {
	queue<int> q;

	q.push(x);
	visited[x] = true;

	while (!q.empty()) {
		int y = q.front();
		q.pop();

		// 스타트링크에 도착하면 함수를 멈춰도 그만
		if (y == g)
			return;

		if (!inRange(y + u));
		else if (visited[y + u]);
		else {
			q.push(y + u);
			step[y + u] = step[y] + 1;
			visited[y + u] = true;
		}

		if (!inRange(y - d));
		else if (visited[y - d]);
		else {
			q.push(y - d);
			step[y - d] = step[y] + 1;
			visited[y - d] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> f >> s >> g >> u >> d;

	bfs(s);

	if (visited[g])
		cout << step[g];
	else
		cout << "use the stairs";

	return 0;
}