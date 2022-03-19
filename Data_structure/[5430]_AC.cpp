/*
	Date: 2022/03/18
	Brief:
	simple implementation + deque
	Reference:
	https://ijsilver.tistory.com/18
	약간의 개념 참고
*/
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	int t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		string cmd;
		int len, i;
		deque<int> dq;
		string arr;
		bool isFront = true;
		bool isError = false;
		cin >> cmd;
		cin >> len;
		cin >> arr;

		for (i = 0; i < arr.length(); i++) {
			int num = 0;
			while ('0' <= arr[i] && arr[i] <= '9') {
				num *= 10;
				num += (arr[i] - '0');
				i++;
			}
			// 숫자일 때만 deque에 push하도록
			if(num != 0)
				dq.push_back(num);
		}
		for (i = 0; i < cmd.length(); i++) {
			if (cmd[i] == 'R') {
				isFront = !isFront;
			}
			else {
				if (isFront && !dq.empty()) {
					dq.pop_front();
					//cout << "pop front\n" << dq.size() << "\n";
				}
				else if (!isFront && !dq.empty()) {
					dq.pop_back();
					//cout << "pop back\n" << dq.size() << "\n";
				}
				else { // this case means dq is empty
					isError = true;
					cout << "error\n";
					break;
				}
			}
		}

		if (!isError && isFront) {
			cout << "[";
			while (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
				if (!dq.empty())
					cout << ",";
			}
			cout << "]\n";
		}
		else if (!isError && !isFront) {
			cout << "[";
			while (!dq.empty()) {
				cout << dq.back();
				dq.pop_back();
				if (!dq.empty())
					cout << ",";
			}
			cout << "]\n";
		}
	}



	return 0;
}