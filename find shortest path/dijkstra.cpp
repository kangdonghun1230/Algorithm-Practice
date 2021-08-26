#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number = 6;
int INF = 100000000;

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2 ,3 ,0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

// check visited or not
bool v[6];
// shortest distance
int d[6];

// ���� ���¿��� �ּ� �Ÿ��� ���� ������ ��ȯ�ϴ� �Լ�
int shortestIndex() {
	int min = INF;
	int idx = 0;

	/*
	����Ž�� : �տ������� �ϳ��� Ž���Ѵ�.
	*/
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			idx = i;
		}
	}

	return idx;
}

// dijkstra
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}

	// start node : visited
	v[start] = true;

	// i index�� ������� �ʰ� �ܼ� �ݺ�Ƚ���� �ǹ��ϸ�, �� ��� ���� - 2���� �ݺ��ϸ� �Ǳ� �����̴�.
	for (int i = 0; i < number - 2; i++) {
		// ���� ����� ��� �湮ó��
		int cur = shortestIndex();
		v[cur] = true;
		for (int j = 0; j < number; j++) {
			if (!v[j]) {
				if (d[cur] + a[cur][j] < d[j]) {
					d[j] = d[cur] + a[cur][j];
				}
			}
		}
	}

}

int main() {
	dijkstra(0);

	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}

	return 0;
}

/*
dijkstra : ������� �˰��ִ� �ִ� ��θ� ������ ���ư��� �˰���

���ͽ�Ʈ�� �˰����� ���̳��� ���α׷��� �Ǵ� �׸��� �˰������� �з��ȴ�.

dp : �ִ� �Ÿ��� ���� ���� �ִ� �Ÿ��� �̷�����ֱ� ����
greedy : ������ ���̸� �����Ͽ� ���� ª�� �ͺ��� �����Ͽ� ����ϱ� ����

dijkstra �۵� ����`
1. ��� ��带 �����Ѵ�.
2. ��� ��带 �������� �� ����� �ּ� ����� �����Ѵ�.
3. �湮���� ���� ��� �߿��� ���� ����� ���� ��带 �����Ѵ�.
4. �ش� ��带 ���ļ� Ư���� ���� ���� ��츦 ����Ͽ� �ּ� ����� �����Ѵ�.
5. �� �������� 3 ~ 4���� �ݺ��Ѵ�.
*/