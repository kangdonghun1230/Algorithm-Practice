#include <iostream>
#define MAX 101

using namespace std;

//����, ����, ���Ĺ� �������� ����
int n, m, k;
//�ִ� ���Ĺ� ������ ũ�⸦ �����ϴ� ����
int res = 0;
//���� ���Ĺ� ������ ũ�⸦ �����ϴ� ����
int cur_trash = 0;

int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inRange(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

void dfs(int x, int y) {
	//dfs ȣ��ɶ� ���� ����� �����غ���.
	res = (res > cur_trash) ? res : cur_trash;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!inRange(nx, ny))
			continue;

		//���� ĭ�� ���Ĺ� �������� ���
		if (arr[nx][ny] == 1 && !visited[nx][ny]) {
			visited[nx][ny] = true;
			cur_trash++;
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		arr[x][y] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//�湮���� ���� ���Ĺ� �������� ũ�⸦ dfs�� �����Ѵ�.
			if (arr[i][j] == 1 && !visited[i][j]) {
				//�湮 ó���ϰ� ���� ���Ĺ� �������� ũ�⸦ 1�� �ʱ�ȭ�� ���·� dfs ȣ��
				visited[i][j] = true;
				cur_trash = 1;
				dfs(i, j);
			}
		}
	}

	cout << res;

	return 0;
}