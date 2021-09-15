#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

vector<int> a[MAX];
int inDegree[MAX], buildNum[MAX];
bool isCheat;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		inDegree[y]++;
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			// �ǹ��� ���� �� ���µ� ���� ���
			if (inDegree[y] != 0) {
				isCheat = true;
				break;
			}
			else {
				if (buildNum[y]++) continue;
				// ó�� ���� �ǹ��� ��� ������ �ǹ����� ���������� �����.
				for (auto it : a[y]) {
					--inDegree[it];
				}
			}
		}
		// x == 2
		else {
			if (buildNum[y] == 0) {
				isCheat = true;
				break;
			}
			else {
				buildNum[y]--;
				if (buildNum[y] > 0) continue;
				// ���� ������ ��� �ǹ��� ����� ��� ���� �ǹ��� ���������� �ø���.
				for (auto it : a[y]) ++inDegree[it];
			}
		}
	}

	if (isCheat) {
		cout << "Lier!\n";
	}
	else {
		cout << "King-God-Emperor\n";
	}

	return 0;
}

/*
�̸� �Է¹��� �����͸� �̿��ؼ� topology sort��
������ �� ������ ����� ����ϴ� ������ �ƴ϶�

������� �����͸� �Է¹����� �� ������� �۾���
�����ϴ� ��� topology sort�� ������� �ʴ�����
�˻��ϸ� ���α׷��� ����ǵ��� �ڵ��ؾ��Ѵ�.
*/