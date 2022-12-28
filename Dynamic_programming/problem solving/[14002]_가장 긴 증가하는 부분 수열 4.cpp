#include <iostream>
#include <vector>

#define MAX 1001

using namespace std;

int N;
// index: ������ index, 1st value: length, 2nd value: prev index
int d[MAX][2];
int arr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		// ���̿� ���� index�� �ʱ�ȭ�Ѵ�.
		d[i][0] = 1;
		d[i][1] = i;
	}

	for (int i = 1; i <= N; i++) {
		int currentValue = arr[i];
		int currentIdx = i;
		for (int j = 0; j < i; j++) {
			int prevValue = arr[j];
			int prevIdx = j;
			// i��° �迭�� ���� ���� ���ҵ��� �ϳ��� ���캻��.
			if (currentValue > prevValue) {
				// ���� ���Ұ� ���� ū ���� ���� �ִ� ���� �����ϴ� �κ� ������ ���̸� ������ �� ���� ���
				if (d[currentIdx][0] > d[prevIdx][0] + 1) {
					continue;
				}
				// �ִ� ���̸� ������ �� �ִ� ���, ���̿� ���� index�� �����Ѵ�.
				else {
					d[currentIdx][0] = d[prevIdx][0] + 1;
					d[currentIdx][1] = j;
				}
			}
		}
	}

	int maxLength = 0;
	int maxIdx = 1;

	for (int i = 1; i <= N; i++) {
		if (maxLength < d[i][0]) {
			maxLength = d[i][0];
			maxIdx = i;
		}
	}

	vector<int> res;
	while (1) {
		// �ڱ� �ڽ��� ���� �� �����ϴ� �κ� ������ �������� ��� �����Ѵ�.
		if (maxIdx == d[maxIdx][1])
			break;
		// �κ� ������ ���� ���ҷ� �̵��ϸ鼭 �ϳ��� vector�� �ִ´�.
		res.push_back(arr[maxIdx]);
		maxIdx = d[maxIdx][1];
	}

	cout << maxLength << '\n';

	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}

	return 0;
}