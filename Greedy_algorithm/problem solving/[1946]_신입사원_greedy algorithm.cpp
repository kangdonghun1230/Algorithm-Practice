#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

vector<pair<int, int>> a;

void greedy() {
	// ù��° �������� ���� �Ϸ�
	sort(a.begin(), a.end());
	
	int cnt = 0; int min = MAX;
	for (int i = 0; i < a.size(); i++) {
		if (min < a[i].second) {
			continue;
		}
		else {
			min = a[i].second;
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		// n : �������� ��
		int n;
		scanf("%d", &n);

		a.clear();

		// get ranking information
		for (int i = 0, x, y; i < n; i++) {
			scanf("%d %d", &x, &y);
			a.push_back({ x, y });
		}

		greedy();
	}

	return 0;
}