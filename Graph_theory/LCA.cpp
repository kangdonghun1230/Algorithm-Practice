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

//dfs ������� �׷����� ��ȸ�ϸ�, �� ����� depth�� �����Ѵ�.
void dfs(int n, int depth) {
	//n�� ����� depth�� �����Ѵ�.
	depths[n] = depth;
	
	for (int i = 0; i < tree[n].size(); i++) {
		if (!visited[tree[n][i]]) {
			visited[tree[n][i]] = true;
			//�ڽ� ����� depth�� +1 ����
			dfs(tree[n][i], depth + 1);
			//�ڽ� ����� 2^0��° �θ�� ���� ���
			dp[tree[n][i]][0] = n;
		}
	}
}

int lca(int a, int b) {
	if (depths[a] < depths[b]) {
		swap(a, b);
	}

	//�� ����� depth�� �����.
	for (int i = 20; i >= 0; i--) {
		//a�� �� ���� ������ b�� ���� ���̸� ���� �� �ִ� i��° �θ� ã�´�.
		if (depths[a] - depths[b] >= (1 << i)) {
			a = dp[a][i];
		}
	}

	//���� ������ �׳� ��ȯ����. (���� ������ ã����)
	if (a == b)
		return a;

	for (int i = 20; i >= 0; i--) {
		//ó������ ������ �ٸ� ����Ʈ�� ã�´�.
		if (dp[a][i] != dp[b][i]) {
			a = dp[a][i];
			b = dp[b][i];
		}
	}

	//���������δ� ���� ������ �ٷ� ���ܿ� ���� ���̴�.
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
		//���� ������ �Է��Ѵ�.
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	visited[1] = true;
	dfs(1, 1);

	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			int halfParent = dp[i][j - 1];
			// halfParent�� j-1��° parent = j��° parent
			dp[i][j] = dp[halfParent][j - 1];
		}
	}

	//testcase�� ������ �Է¹޴´�.
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << "\n";
	}

	return 0;
}