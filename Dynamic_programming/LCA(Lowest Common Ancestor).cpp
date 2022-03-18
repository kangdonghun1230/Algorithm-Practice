/*
	* 이번에 정리할 최소 공통 조상(Lowest Common Ancestor) 개념은 일종의 dp입니다.
	* 두 노드 사이의 최소 공통 조상을 찾아 두 노드 사이의 거리를 빠르게 구할 때 사용합니다.
	* 굳이 이진 트리를 사용할 필요 없이 일반적인 형태의 트리에 모두 적용이 가능합니다.
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
			tmp는 j의 2^(i-1)번째 조상이고,
			j의 i번째 조상은 tmp의 2^(i-1)번째 조상과 같다.
			
			"2^(i-1) + 2^(i-1) = 2^i"이기 떄문이다.
			**/
			int tmp = parent[j][i - 1];
			parent[j][i] = parent[tmp][i - 1];
		}
	}
	return;
}

int LCA(int x, int y) {
	// y가 더 깊은 depth이도록 설정
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

	// 부모가 같은 경우에는 반환합니다.
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