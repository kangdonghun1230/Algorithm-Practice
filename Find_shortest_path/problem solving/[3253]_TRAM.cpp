#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define endl "\n"

using namespace std;

int a, b, n;
const int INF = 98765432;

vector<int> crossRail[MAX];
int dp[MAX];

void dijkstra(int x) {
	queue<int> q;
	q.push(x);
	dp[x] = 0;
	while (!q.empty()) {
		int y = q.front();
		int num = dp[y];
		q.pop();

		for (int i = 0; i < crossRail[y].size(); i++) {
			int z = crossRail[y][i];

			if (i != 0) {
				num = dp[y] + 1;
			}

			if (dp[z] > num) {
				//cout << z << " " << dp[x] << " " << num << endl;
				q.push(z);
				dp[z] = num;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++) {
		int Ki;
		cin >> Ki;

		for (int j = 0; j < Ki; j++) {
			int tmp;
			cin >> tmp;
			crossRail[i].push_back(tmp);
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
	}

	dijkstra(a);

	if (dp[b] == INF)
		cout << "-1" << endl;
	else
		cout << dp[b] << endl;

	return 0;
}