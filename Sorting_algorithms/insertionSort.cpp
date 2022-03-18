/*
* @brief insertion sort의 개념을 바탕으로 구현한 간단한 코드이다.
* @date 2021/08/08
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O N^2 (같은 시간복잡도의 algirthm 중 가장 강력하다.)
*/
#include <iostream>

using namespace std;

int main() {
	int i, j, tmp;
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (i = 0; i < 9; i++) {
		j = i;
		while (arr[j] > arr[j + 1]) {
			tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
			j--;
		}
	}

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
/*
정렬이 거의 완료된 경우에는 굉장히 효율적이다.
따라서 거의 정렬이 완료된 상태에서는 삽입 정렬이 가장 빠른 정렬 알고리즘이다.
*/