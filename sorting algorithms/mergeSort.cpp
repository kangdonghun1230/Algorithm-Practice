/*
* @brief merge sort의 개념을 바탕으로 구현한 간단한 코드이다.
* @date 2021/08/11
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O N*logN (같은 시간복잡도의 algorithm 중 가장 강력하다.)
*/
#include <stdio.h>
#define Num 8

int sorted[8]; // 정렬 배열은 반드시 전역 변수로 선언 (불필요한 메모리 사용을 방지)

// 시작점, 중간점, 끝점을 argument로 받는다.
void merge(int arr[], int m, int mid, int n) {
	int i = m;
	int j = mid + 1;
	// k는 sorted array의 index를 의미한다.
	int k = m;
	// 작은 순서대로 배열에 삽입
	while (i <= mid && j <= n) {
		if (arr[i] < arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	// i or j가 먼저 끝나 나머지에 대한 처리를 하는 부분
	if (i > mid) {
		for (int t = j; t <= n; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	// 정렬된 배열을 삽입하는 과정
	for (int t = m; t <= n; t++) {
		arr[t] = sorted[t];
	}
}
/*
mergeSort 함수가 재귀적으로 수행되기 때문에
배열의 원소가 차례대로 정렬되며 합쳐진다.
*/
void mergeSort(int arr[], int m, int n) {
	// 크기가 1보다 큰 경우
	if (m < n) {
		int mid = (m + n) / 2;
		// mid 기준으로 양옆 정렬한 후 merge한다.
		mergeSort(arr, m, mid);
		mergeSort(arr, mid + 1, n);
		merge(arr, m, mid, n);
	}
}

int main() {
	int arr[Num] = { 7, 6, 5, 8, 3, 5, 9, 1 };
	mergeSort(arr, 0, Num - 1);

	for (int i = 0; i < Num; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

/*
일단 반으로 쪼개고 나중에 합하는 algorithm

quick sort 보다 빠르지는 않지만,
n log n의 시간복잡도를 보장하는 algorithm이다.

정렬하기 위해 전역 변수로 배열을 하나 선언해야 하기 때문에
메모리를 조금 낭비하긴 하지만,
시간 복잡도를 보장한다는 점에서 좋은 algorithm이다.
*/