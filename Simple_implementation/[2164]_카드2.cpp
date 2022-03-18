/*
	Date: 2022/02/10
	Brief:
	simple implementation problem
	Reference:
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	queue<int> q;
	cin.tie(NULL);
	cin >> n;

	if (n == 1) {
		cout << "1\n";
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (1) {
		// 맨 앞의 카드 버리고
		q.pop();
		if (q.size() == 1) break;

		// 다음 카드를 뽑아서 맨 뒤에 넣어준다.
		int x = q.front();
		q.pop();
		q.push(x);
	}
	cout << q.front() << "\n";

	return 0;
}

/*
1. 이런 방식으로 element를 넣고 뺄 수 있는 자료구조 있나?
2. queue
3. queue 사용해보자.
4. queue 사용하니까 그냥 해결됨.
*/