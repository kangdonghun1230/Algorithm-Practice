/*
* @brief bubble sort의 개념을 바탕으로 구현한 간단한 코드이다.
* @date 2021/08/07
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O N^2
*/
#include <iostream>

using namespace std;

int main() {
	int i, j, tmp;
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (i = 1; i < 10; i++) {
		for (j = 0; j < 10 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	// print result of bubble sort
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}