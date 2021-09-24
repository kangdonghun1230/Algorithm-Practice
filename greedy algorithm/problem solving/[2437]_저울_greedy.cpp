#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int w[MAX];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	sort(w, w + n);

	int min_weight = 1;
	for (int i = 0; i < n; i++) {
		if (w[i] > min_weight) break;
		min_weight += w[i];
	}

	cout << min_weight << endl;

	return 0;
}

/*
점화식을 통한 증명까지는 알겠는데
애초에 등장한 위의 점화식이 의미하는 바가
유도된 이유를 이해하지 못하겠다.

위의 조건을 만족하는 경우 min_weight이하의 모든 값들을
가진 추를 가지고 만들어 낼 수 있는 이유를 모르겠다.

다시 마주쳐도 현재로서는 못 풀 문제이다.
*/