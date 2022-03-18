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
	// minH ~ maxH ��� ���̸� �����ذ��� brute force ���·� Ž���ϸ� ������ �� ã��
	for (i = minH; i <= maxH; i++) {
		int buildNum = 0;
		int breakNum = 0;

		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				int tmp = i - map[j][k];

				if (tmp < 0) // ���� ĭ���� �׾ƾ� �ϴ� ���
					breakNum += (-tmp);
				else // ���� ĭ���� ��ƾ� �ϴ� ���
					buildNum += tmp;
			}
		}
		// ������ ��ϰ� ���� ������� �ش� case�� ���� �� �ִ� ��쿡�� ��
		if (buildNum <= breakNum + B) {
			int tmp = buildNum + 2 * breakNum;
			if (minTime > tmp) {
				minTime = tmp;
				height = i;
			}
			// minTime ��ġ�� ���� ��� ���̰� �� ���� ��츦 �����Ѵ�.
			else if (minTime == tmp && height < i) {
				height = i;
			}
		}
	}
	cout << minTime << " " << height << "\n";

	return 0;
}

/*
	1��: ��� �����ؼ� �κ��丮�� (2��)
	2��: ��� �ϳ� �������� (1��)

	�� ���� �۾��� �ɸ��� �ּ� �ð��� �� ��� ���� ���̸� ����Ͻÿ�.
	������ �� ����� ������ B��, ���� ���̴� 256�� �ʰ��� �� ����. (+����x)

	���࿡ ���� ���� �� �ִٸ� �� �߿��� ���� ���̰� ���� ���� ���� ����϶�!
*/