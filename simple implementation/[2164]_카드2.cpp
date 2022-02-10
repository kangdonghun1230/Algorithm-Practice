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
		// �� ���� ī�� ������
		q.pop();
		if (q.size() == 1) break;

		// ���� ī�带 �̾Ƽ� �� �ڿ� �־��ش�.
		int x = q.front();
		q.pop();
		q.push(x);
	}
	cout << q.front() << "\n";

	return 0;
}

/*
1. �̷� ������� element�� �ְ� �� �� �ִ� �ڷᱸ�� �ֳ�?
2. queue
3. queue ����غ���.
4. queue ����ϴϱ� �׳� �ذ��.
*/