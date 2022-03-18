#include <iostream>
#define MAX 11
using namespace std;

int a[MAX];
int result[MAX];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		int x = a[i];

		int j = 1;
		int jump = 0;
		for (j; j <= n; j++) {
			if (jump == x && result[j] == 0) {
				result[j] = i;
				break;
			}
			if (result[j] == 0) jump++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}cout << endl;

	return 0;
}

/*
이 문제는 결국 입력으로 들어오는 정보가 키가 작은 순서대로 입력되는데,
해당 정보는 결과 sequence의 공란을 몇 칸 띄어서 앉아야 본인의 자리를 의미
하는지에 해당합니다.

위 개념을 활용하여 문제는 쉽게 해결이 가능하였으나 공란을 패스하는 알고리즘을
구현하는데 있어 타인의 구현 코드를 참고했습니다.
*/