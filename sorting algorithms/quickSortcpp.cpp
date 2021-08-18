/*
* @brief quick sort의 개념을 바탕으로 구현한 간단한 코드이다.
* @date 2021/08/09
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O N*logN (같은 시간복잡도의 algirthm 중 가장 강력하다.)
*/
#include <stdio.h>

int num = 10;
int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* arr, int start, int end) {
	if (start >= end) {
		// 원소가 1개인 경우에 해당한다.
		return;
	}
	// pivot을 첫 번째 값으로 선택
	int key = start;
	int i = start + 1;	// 왼쪽부터 큰 값을 찾기 위한 index
	int j = end;		// 오른쪽부터 작은 값을 찾기 위한 index
	int tmp;			// 두 변수의 값 변경을 위한 variable

	while (i <= j) {	// 엇갈릴 때까지
		while (arr[i] <= arr[key])
			i++;
		// 엇갈리는 경우 왼쪽에 있는 값과 pivot을 바꾸기 때문에 j의 범위를 설정해준다.
		while (arr[j] >= arr[key] && j > start)
			j--;

		if (i > j) {	// 엇갈리는 경우
			tmp = arr[j];
			arr[j] = arr[key];
			arr[key] = tmp;
		}
		else {			// 엇갈리지 않는 경우
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	// 옮겨진 pivot을 기준으로 왼쪽, 오른쪽에 대해서 병렬적으로 quick sorting 할 수 있도록
	// recursive call
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}


int main() {
	quickSort(arr, 0, num - 1);
	
	for (int i = 0; i < num; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}

/*
왼 -> 오 : pivot보다 큰 값을 찾는다.
오 -> 왼 : pivot보다 작은 값을 찾는다.
서로 엇갈리게 되면 왼쪽에 있는 값와 pivot을 바꿔준다.
이렇게 교환하게 되면, 기존 pivot 보다 왼쪽에 있는 값은 pivot보다 작은 값을 갖고,
오른쪽에 있는 값들은 기존 pivot보다 큰 값을 갖게 된다.

교환된 기존 pivot의 왼쪽, 오른쪽에 대해서 pivot을 재설정하여 병렬적으로
정렬 작업을 재개하며 quick sorting이 진행된다.

하지만, 최악의 경우에는 N^2의 시간복잡도를 갖는 경우도 발생한다.
물론 대부분의 경우에는 빠르게 처리해준다. 대회에서 N*logN을 요구하는 경우 틀릴수도
1, 2, 3, 4, 5, 6, 7, 8, 9, 10 이런 식으로 이미 정렬된 데이터들을 quick sorting 하는 경우에
앞서 말했듯 N^2의 시간 복잡도를 갖게 된다.
*/