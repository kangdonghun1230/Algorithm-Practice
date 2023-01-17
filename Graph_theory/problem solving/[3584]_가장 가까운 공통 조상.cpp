#include <iostream>

#define MAX 10001
#define endl '\n'

using namespace std;

int p[MAX];
int n;

void init() {
	//초기에는 자기 자신을 부모로 가리킨다. (아무것도 연결 x)
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
}

//a가 b의 부모이다.
void setParent(int a, int b) {
	p[b] = a;
	return;
}

int findSameParent(int a, int b) {
	int parentA = a;
	int parentB = b;

	bool visited[MAX] = { false, };
	visited[parentA] = true;
	
	while (1) {
		if (parentA == p[parentA])
			break;

		parentA = p[parentA];
		visited[parentA] = true;
	}

	while (1) {
		if (visited[parentB])
			break;

		parentB = p[parentB];
	}

	return parentB;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;

	while (t--) {
		cin >> n;
		init();

		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;

			setParent(a, b);
		}

		int a, b; //공통 조상을 구하고 싶은 두 개의 노드
		cin >> a >> b;

		cout << findSameParent(a, b) << endl;
	}

	return 0;
}