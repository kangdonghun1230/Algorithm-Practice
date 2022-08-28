/*
	Date: 2022/08/28
	Brief:
	�̺� Ž��
	Reference:
	https://st-lab.tistory.com/277
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> homeSite;

int installRouter(int);

// upper bound ��Ŀ� ���� �̺� Ž�� �˰����� �����ؾ� �Ѵ�.
// ������ �����ϴ� �ִ��� �����ؾ� �ϱ� �����̴�.
int binarySearch() {
	// lo: �Ÿ��� �ּڰ�, hi: �Ÿ��� �ִ� (1���� ��ġ�ϴ� ���?)
	int lo = 1, hi = homeSite[n-1] + 1;

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		//cout << lo << " " << hi << endl;
		if (installRouter(mid) < c) {
			// ��ġ ������ ������ ���ڰ� ���� ��� �Ÿ��� �ٿ���
			hi = mid;
		}
		else {
			// ��ġ ������ ������ ���ڰ� ���� ��� �Ÿ��� �÷��� �ȴ�.
			lo = mid + 1;
		}

	}
	// hi�� ���Ѽ��̹Ƿ�
	return hi - 1;
}

int installRouter(int dis) {
	int cnt = 1;

	int prev = homeSite[0];

	for (int i = 1; i < n; i++) {
		int cur = homeSite[i];
		// ������ ��ġ�� ������ ��ġ�� dis���� ���� ��� ���� ������ ������ ��ġ��
		// �Ұ����ϴ�.
		if (cur - prev < dis)
			continue;
		// ������ ��ġ�� ������ ��� prev �� ��ġ�� �����ϰ�, ������ ���� count
		prev = cur;
		cnt++;
	}

	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		homeSite.push_back(tmp);
	}
	sort(homeSite.begin(), homeSite.end());
	cout << binarySearch();

	return 0;
}

/*
n���� ���� ��ǥ�� �־����� ��, c���� �����⸦ �ּ��� �������� ��ġ�� ��
�� ������ ���� �� �ִ� �ִ븦 ���Ѵ�.

* �̺� Ž������ Ǯ���ؾ� �ϴ� �����̴�.
* �̺� Ž���� ���� �������� ��ƾ� �ϴ� ���� �Ÿ��̴�.
* �Ÿ��� ���� ��ġ ������ ������ ����� �ٲ��
* ��ġ�� �� �ִ� ������ ����� ���� Ž���� �����ؾ� �Ǳ� �����̴�.
* �߰������� �ִ��� �Ÿ��� ���ϴ� ���� ��ǥ�̱� ������ upper bound �������� �̺� Ž���� �����ؾ� �Ѵٰ� ��.

*/