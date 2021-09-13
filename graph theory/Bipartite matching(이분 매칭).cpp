/*
* @brief �̺и�Ī ���信 ���� ������ �ڵ�
* @date 2021/09/05
* @author ������
* @parameter nothing
* @return print result SCC vector
* @big O O(V * E)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
// the number of node, the number of edge
int n = 3, e;

// matching success -> true, matching fail -> false
bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// skip already handled node
		if (c[y])
			continue;
		// c: true -> handled node
		c[y] = true;

		// none matching node or request for change to connected node
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	// matching fail
	return false;
}

int main() {
	//n = 2, e = 3;
	////scanf("%d %d", &n, &e);
	//a[1].push_back(1);
	//a[1].push_back(2);

	//a[2].push_back(1);
	//a[2].push_back(2);
	//
	//a[3].push_back(1);
	//a[3].push_back(2);

	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		// initialize c array with false (at every dfs traversal)
		fill(c, c + MAX, false);
		if (dfs(i)) cnt++;
	}

	printf("%d\n", cnt);

	for (int i = 1; i <= n; i++) {
		printf("%d -> %d\n", d[i], i);
	}

	return 0;
}

/*
���� ��Ʈ��Ŭ �÷ο� �˰������ε� �ذ��� �� �ִ� ������ ��
2���� �������� ������ �ִ� ��쿡 ���ؼ� ���� ������ �ڵ带 ©
�� �ִ� �����Դϴ�.

�� �׷��� �ִ��� ��Ī ��Ű�� ���� ��ǥ�� �ϴ� �˰����̰�, �̸�
'�ִ� ��ĥ'�� ��ǥ�� �Ѵٰ� �մϴ�. �� ������ �÷ο� �������� ����
�ϸ� ��Ʈ��ũ �÷ο�� ��Ȯ�� ��ġ�ϰ� �˴ϴ�.

������ ����� ��Ʈ��ũ �÷ο� �˰����� ������ ī�� �˰�����
�ð� ���⵵�� O(V * E ^ 2)�����ϴ�.
�̺и�Ī�� ���� �̰ͺ��� �� ������ ȿ������ �˰����� ������ �� �ִµ�,
�ٷ� DFS�� �̿��ϸ� �˴ϴ�. 

-----------------------------------------------

(BFS, DFS�� ũ�� �ǹ� ���� �� ����. �ֳ��ϸ� ������ Ž���� �ϴ� ����� ���̰�
1�� ���� �����̱� ������ BFS, DFS ��� ������� Ž���Ѵٰ� ���ϴ� ���� �ָ��ϴٰ�
�����Ѵ�.)

-----------------------------------------------

�� ������� ��Ʈ��ũ �÷ο��� ������ �ذ��ҽ� �ð����⵵�� O(V + E)���� ������ �� �ֽ��ϴ�.
(��� ��尡 �ڽŰ� ����� ������ ����ŭ�� �ִ�� Ž���� �����ϱ� ����)

���� ���� �ӵ��� �ƴ�����, ���� �����ϰ� ���� ������ �� �ִٴ� ������ ���� ���� ����ϴ�
�˰����̶�� �մϴ�.
*/