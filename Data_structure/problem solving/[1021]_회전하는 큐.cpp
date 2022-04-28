/*
	Date: 2022/04/28
	Brief:
	Data structure
	Reference:
*/
#include <iostream>
#include <deque>

using namespace std;

// class for normalization deque data structure
class Deque {
private:
	deque<int> dq;

public:
	Deque(int n) {
		int i;
		for (i = 1; i <= n; i++) {
			dq.push_back(i);
		}
	}

	void op2() {
		int num = dq.front();
		dq.pop_front();
		dq.push_back(num);
	}

	void op3() {
		int num = dq.back();
		dq.pop_back();
		dq.push_front(num);
	}

	int getOneElement(int idx) {
		int tmp = 1;
		int cnt = 0;
		for (auto it = dq.begin(); it != dq.end(); it++) {
			if (*it == idx)
				break;
			tmp++;
		}

		int size = dq.size();
		// if size is even number: 1 2 3 4 5 6 7 8 -> 8/2 = 4까지 op2 is better
		// if size is odd number: 1 2 3 4 5 6 7 8 9 -> 9/2 + 1 = 5까지 op2 is better
		// 5(op2): 4번, 5(op3): 5번이기 때문에
		if (tmp <= size / 2 + size % 2) {
			for (int i = 1; i < tmp; i++) {
				op2();
				cnt++;
			}
		}
		else {
			for (int i = tmp; i <= size; i++) {
				op3();
				cnt++;
			}
		}
		//cout << "pop front: " << dq.front() << "\n";
		dq.pop_front();

		return cnt;
	}
};

int main() {
	int n, m;
	int i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	Deque dq(n);
	int res = 0;
	for (i = 0; i < m; i++) {
		int idx;
		cin >> idx;
		// count the number of the each operations
		res += dq.getOneElement(idx);
	}
	cout << res << "\n";
	return 0;
}