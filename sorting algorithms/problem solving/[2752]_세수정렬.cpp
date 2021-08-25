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
		// 절댓값이 1000보다 작거나 같은 정수이기 때문에
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
online problem solving site는 1초에 대략 1억번 연산 가능하다고
가정하고 문제를 풀면 된다.

즉, 현재 문제는 N^2 시간 복잡도를 갖는 정렬 알고리즘을 사용해도 문제가 없다.
*/