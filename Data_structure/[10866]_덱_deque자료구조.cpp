/*
	Date: 2022/02/16
	Brief:
	simple implementation problem using deqeue structure
	Reference:
*/
#include <iostream>
#include <deque>

using namespace std;

class Deque {
private:
	deque<int> dq;
public:
	// push_front
	void pushFront(int x) {
		dq.push_front(x);
	}
	// push_back
	void pushBack(int x) {
		dq.push_back(x);
	}
	// pop_front
	void popFront() {
		if (dq.empty()) {
			cout << "-1\n";
		}
		else {
			cout << dq.front() << "\n";
			dq.pop_front();
		}
	}
	// pop_back
	void popBack() {
		if (dq.empty()) {
			cout << "-1\n";
		}
		else {
			cout << dq.back() << "\n";
			dq.pop_back();
		}
	}
	// size
	void size() {
		cout << dq.size() << "\n";
	}
	// empty
	void empty() {
		if (dq.empty()) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
	// front
	void front() {
		if (dq.empty()) {
			cout << "-1\n";
		}
		else {
			cout << dq.front() << "\n";
		}
	}
	// back
	void back() {
		if (dq.empty()) {
			cout << "-1\n";
		}
		else {
			cout << dq.back() << "\n";
		}
	}
};

int main() {
	Deque dq = Deque();
	int n, i;
	cin.tie(NULL);
	cin >> n;

	for (i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_back") {
			int num;
			cin >> num;

			dq.pushBack(num);
		}
		else if(cmd == "push_front") {
			int num;
			cin >> num;

			dq.pushFront(num);
		}
		else if(cmd == "front") {
			dq.front();
		}
		else if (cmd == "back") {
			dq.back();
		}
		else if (cmd == "empty") {
			dq.empty();
		}
		else if (cmd == "pop_back") {
			dq.popBack();
		}
		else if (cmd == "pop_front") {
			dq.popFront();
		}
		else if (cmd == "size") {
			dq.size();
		}
	}

	return 0;
}