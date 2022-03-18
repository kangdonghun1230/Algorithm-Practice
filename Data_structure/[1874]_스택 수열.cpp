/*
	Date: 2022/02/19
	Brief:
	simple implementation problem solving with 
	data structure stack
	Reference:
*/
#include <iostream>
#include <stack>
#include <string>

#define MAX 100001

using namespace std;

int arr[MAX];
bool pushed[MAX];

int main() {
	int n, i, j;
	int num, lastNum = 0;
	stack<int> s;
	string res;

	cin.tie(NULL);
	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		num = arr[i];

		if (lastNum < num && pushed[num] == false) {
			for (j = lastNum + 1; j <= num; j++) {
				s.push(j);
				pushed[j] = true;
				res += "+";
			}
			// num까지 push한 후에 마지막에 pop해주면 된다.
			s.pop();
			res += "-";
			lastNum = num;
		}
		else {
			int tmp = s.top();
			if (num != tmp) {
				cout << "NO\n";
				return 0;
			}
			else {
				s.pop();
				res += "-";
			}
		}
	}

	for (i = 0; i < res.size(); i++) {
		cout << res[i] << "\n";
	}

	return 0;
}

/*
	마지막 수보다 큰 수가 수열의 다음 원소이면, push하고
	작은 수가 수열의 다음 원소인 경우 pop 연산을 수행해서 
	다음 원소를 만들 수 있는지 판단할 수 있을 것 같다.
*/