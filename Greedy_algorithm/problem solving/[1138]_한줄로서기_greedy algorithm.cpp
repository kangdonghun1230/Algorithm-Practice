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
�� ������ �ᱹ �Է����� ������ ������ Ű�� ���� ������� �ԷµǴµ�,
�ش� ������ ��� sequence�� ������ �� ĭ �� �ɾƾ� ������ �ڸ��� �ǹ�
�ϴ����� �ش��մϴ�.

�� ������ Ȱ���Ͽ� ������ ���� �ذ��� �����Ͽ����� ������ �н��ϴ� �˰�����
�����ϴµ� �־� Ÿ���� ���� �ڵ带 �����߽��ϴ�.
*/