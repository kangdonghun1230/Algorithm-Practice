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
			// 건물을 지을 수 없는데 지은 경우
			if (inDegree[y] != 0) {
				isCheat = true;
				break;
			}
			else {
				if (buildNum[y]++) continue;
				// 처음 짓는 건물인 경우 인접한 건물들의 진입차수를 낮춘다.
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
				// 같은 종류의 모든 건물이 사라진 경우 인접 건물의 진입차수를 올린다.
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
미리 입력받은 데이터를 이용해서 topology sort를
진행한 후 정렬의 결과를 출력하는 문제가 아니라

순서대로 데이터를 입력받으며 이 순서대로 작업을
진행하는 경우 topology sort에 위배되지 않는지를
검사하며 프로그램이 진행되도록 코딩해야한다.
*/