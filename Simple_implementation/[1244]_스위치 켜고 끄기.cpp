/*
	Date: 2022/07/29
	Brief:
	Implementation
	Reference:
*/
#include <iostream>

using namespace std;

int n;
int studentNum;
bool switchStatus[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> switchStatus[i];
	}

	cin >> studentNum;

	for (int i = 0; i < studentNum; i++) {
		int sex, num;
		cin >> sex >> num;

		// 남자 학생
		if (sex == 1) {
			for (int i = num; i <= n; i += num) {
				// 상태를 뒤집는다.
				switchStatus[i] = !switchStatus[i];
			}
		}
		else {
			switchStatus[num] = !switchStatus[num];
			for (int i = 0; i <= n / 2; i++) {
				if (num - i <= 0 || num + i > n)
					break;
				else if (switchStatus[num - i] == switchStatus[num + i]) {
					switchStatus[num - i] = !switchStatus[num - i];
					switchStatus[num + i] = !switchStatus[num + i];
				}
				else
					break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << switchStatus[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}

	return 0;
}