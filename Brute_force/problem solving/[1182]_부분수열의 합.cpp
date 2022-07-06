/*
	Date: 2022/07/07
	Brief:
	Brute-Force
	Reference:
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[21];
int n, s;
int res_cnt;
int total;
// ����ؼ� ����� ���� ���� Ʈ���� �������ѳ����� ������� ����
// �ð� ���⵵ ����Ǳ� ������, �ܼ� ���Ʈ������ �ذ�
void sumFunc(int cnt, int sum) {
	if (cnt == n) {
		if (sum == s) {
			res_cnt++;
		}

		return;
	}
	// ���� element ����
	sumFunc(cnt + 1, sum + arr[cnt]);
	// ���� element ������
	sumFunc(cnt + 1, sum);
}

int main() {
	int i, j;

	cin.tie(NULL);

	cin >> n >> s;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sumFunc(0, 0);

	// ���� �������� ���� ��� 0�� �����ϱ� �����̴�.
	if (s == 0) res_cnt--;

	cout << res_cnt << "\n";

	return 0;
}

/*
���� �ִ� ����� ���� �������� 100��ȸ���� �̹Ƿ�
1�� ������ �Ҹ�ȴ�. �ٵ�, �ð� ������ 2���̹Ƿ� 
��� �κм����� üũ�ϸ鼭 -> S�� ���� �Ǵ� ��츦 ã���� �ȴ�.
*/
