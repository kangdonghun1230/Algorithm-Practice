/*
	Date: 2022/02/19
	Brief:
	simple implementation problem solving with
	data structure stack
	Reference:
	https://sorious77.tistory.com/74
*/
#include <iostream>
#include <climits> // for INT_MAX
#define MAX 501

using namespace std;

int map[MAX][MAX];

int main() {
	int N, M, B;
	int i, j, k;
	int minH = 257, maxH = 0;
	int minTime = INT_MAX;
	int height = 0;

	cin.tie(NULL);

	cin >> N >> M >> B;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];

			maxH = maxH < map[i][j] ? map[i][j] : maxH;
			minH = minH > map[i][j] ? map[i][j] : minH;
		}
	}
	// minH ~ maxH 모든 높이를 조정해가며 brute force 형태로 탐색하면 최적의 값 찾기
	for (i = minH; i <= maxH; i++) {
		int buildNum = 0;
		int breakNum = 0;

		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				int tmp = i - map[j][k];

				if (tmp < 0) // 현재 칸보다 쌓아야 하는 경우
					breakNum += (-tmp);
				else // 현재 칸보다 깎아야 하는 경우
					buildNum += tmp;
			}
		}
		// 제거한 블록과 보유 블록으로 해당 case를 만들 수 있는 경우에만 비교
		if (buildNum <= breakNum + B) {
			int tmp = buildNum + 2 * breakNum;
			if (minTime > tmp) {
				minTime = tmp;
				height = i;
			}
			// minTime 수치가 같은 경우 높이가 더 높은 경우를 선택한다.
			else if (minTime == tmp && height < i) {
				height = i;
			}
		}
	}
	cout << minTime << " " << height << "\n";

	return 0;
}

/*
	1번: 블록 제거해서 인벤토리행 (2초)
	2번: 블록 하나 꺼내놓기 (1초)

	땅 고르기 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.
	시작할 때 블록의 개수는 B개, 땅의 높이는 256을 초과할 수 없다. (+음수x)

	만약에 답이 여러 개 있다면 그 중에서 땅의 높이가 가장 높은 것을 출력하라!
*/