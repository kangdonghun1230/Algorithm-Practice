#include <iostream>
#define INF 10000001

using namespace std;

int num = 4;

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// initialize result array
	int d[4][4];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = ���İ��� ���
	for (int k = 0; k < num; k++) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				// k�� ���İ��� ��찡 �� �ִܰŸ��� ��� �����Ѵ�.
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// print result
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}

int main() {
	floydWarshall();

	return 0;
}
/*
Floyd Warshall algorithm : ��� �������� �����Ͽ�
�׷��� ���� ��� �������� ���ϴ� ȸ�� ����� �����
����ϴ� �˰����̴�.

dynamic programming ����� �״�� �����Ͽ�
������ �ذ��ϰ� �ִ�.
*/