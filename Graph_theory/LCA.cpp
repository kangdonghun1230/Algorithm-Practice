#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int depths[MAX];
vector<int> tree[MAX];

//1st: node index, 2nd: "2^idx"th parent
int dp[MAX][21];
bool visited[MAX];
int n;

//dfs 방식으로 그래프를 순회하며, 각 노드의 depth를 설정한다.
void dfs(int n, int depth) {
	//n번 노드의 depth를 지정한다.
	depths[n] = depth;
	
	for (int i = 0; i < tree[n].size(); i++) {
		if (!visited[tree[n][i]]) {
			visited[tree[n][i]] = true;
			//자식 노드의 depth는 +1 증가
			dfs(tree[n][i], depth + 1);
			//자식 노드의 2^0번째 부모는 현재 노드
			dp[tree[n][i]][0] = n;
		}
	}
}

int lca(int a, int b) {
	if (depths[a] < depths[b]) {
		swap(a, b);
	}

	//두 노드의 depth를 맞춘다.
	for (int i = 20; i >= 0; i--) {
		//a가 더 깊은 선에서 b와 가장 차이를 좁힐 수 있는 i번째 부모를 찾는다.
		if (depths[a] - depths[b] >= (1 << i)) {
			a = dp[a][i];
		}
	}

	//벌써 같으면 그냥 반환하자. (공통 조상을 찾은셈)
	if (a == b)
		return a;

	for (int i = 20; i >= 0; i--) {
		//처음으로 조상이 다른 포인트를 찾는다.
		if (dp[a][i] != dp[b][i]) {
			a = dp[a][i];
			b = dp[b][i];
		}
	}

	//최종적으로는 공통 조상이 바로 윗단에 있을 것이다.
	return dp[a][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int start, end;
		cin >> start >> end;
		//간선 정보를 입력한다.
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	visited[1] = true;
	dfs(1, 1);

	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			int halfParent = dp[i][j - 1];
			// halfParent의 j-1번째 parent = j번째 parent
			dp[i][j] = dp[halfParent][j - 1];
		}
	}

	//testcase의 개수를 입력받는다.
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << "\n";
	}

	return 0;
}