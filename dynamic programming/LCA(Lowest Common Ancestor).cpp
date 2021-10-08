/*
	* �̹��� ������ �ּ� ���� ����(Lowest Common Ancestor) ������ ������ dp�Դϴ�.
	* �� ��� ������ �ּ� ���� ������ ã�� �� ��� ������ �Ÿ��� ������ ���� �� ����մϴ�.
	* ���� ���� Ʈ���� ����� �ʿ� ���� �Ϲ����� ������ Ʈ���� ��� ������ �����մϴ�.
*/
#include <iostream>
#include <vector>
#define MAX 1001
#define LOG 11

using namespace std;

int n, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];


void dfs(int x, int depth) {
	c[x] = true;
	d[x] = depth;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];

		if(c[y]) continue;
		parent[y][0] = x;
		// call child recursively
		dfs(y, depth + 1);
	}
	return;
}

void setParent() {
	/* call dfs to initialize whole depth information */
	dfs(0, 0);
	for (int i = 1; i < LOG; i++) {
		for (int j = 0; j < n; j++) {
			/**
			tmp�� j�� 2^(i-1)��° �����̰�,
			j�� i��° ������ tmp�� 2^(i-1)��° ����� ����.
			
			"2^(i-1) + 2^(i-1) = 2^i"�̱� �����̴�.
			**/
			int tmp = parent[j][i - 1];
			parent[j][i] = parent[tmp][i - 1];
		}
	}
	return;
}

int LCA(int x, int y) {
	// y�� �� ���� depth�̵��� ����
	if (d[x] > d[y]) {
		swap(x, y);
	}

	// repeat until two points have same depth
	for (int i = LOG - 1; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			// move to "1 << i"th parent
			y = parent[y][i];
		}
	}

	// �θ� ���� ��쿡�� ��ȯ�մϴ�.
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		// go upstream to parent
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
		// when for loop is exited, two points are in the place where they have same parent at deepest depth
	}
	// return LCA
	return parent[x][0];
}

void linkTwoNode(int x, int y) {
	if (x == y) return;
	a[x].push_back(y);
	a[y].push_back(x);
	return;
}

int main() {
	n = 21;

	/* make tree */
	linkTwoNode(1, 0);
	linkTwoNode(2, 0);
	linkTwoNode(3, 1);
	linkTwoNode(4, 1);
	linkTwoNode(5, 2);
	linkTwoNode(6, 2);
	linkTwoNode(7, 3);
	linkTwoNode(8, 3);
	linkTwoNode(9, 4);
	linkTwoNode(10, 4);
	linkTwoNode(11, 4);
	linkTwoNode(12, 8);
	linkTwoNode(13, 8);
	linkTwoNode(14, 9);
	linkTwoNode(15, 10);
	linkTwoNode(16, 13);
	linkTwoNode(17, 13);
	linkTwoNode(18, 14);
	linkTwoNode(19, 15);
	linkTwoNode(20, 17);
	setParent();

	cout << "5, 7's LCA " << LCA(5, 7) << endl;
	cout << "18, 11's LCA " << LCA(18, 11) << endl;
	cout << "10, 9's LCA " << LCA(10, 9) << endl;

	return 0;
}

/*
<Reference>
https://blog.naver.com/PostView.naver?blogId=ndb796&logNo=221282478466&parentCategoryNo=&categoryNo=128&viewDate=&isShowPopularPosts=false&from=postList
https://www.crocus.co.kr/660
*/