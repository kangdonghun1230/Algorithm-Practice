#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, j, num, min, idx, tmp;
	int arr[1001];

	num = 3;

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < num; i++) {
		// ������ 1000���� �۰ų� ���� �����̱� ������
		min = 1000001;
		for (j = i; j < num; j++) {
			if (arr[j] < min) {
				min = arr[j];
				idx = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}

	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

	return 0;
}

/*
online problem solving site�� 1�ʿ� �뷫 1��� ���� �����ϴٰ�
�����ϰ� ������ Ǯ�� �ȴ�.

��, ���� ������ N^2 �ð� ���⵵�� ���� ���� �˰����� ����ص� ������ ����.
*/