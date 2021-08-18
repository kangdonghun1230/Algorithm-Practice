/*
* @brief selection sort의 개념을 바탕으로 구현한 간단한 코드이다.
* @date 2021/08/06
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O n^2
*/
#include<iostream>
#define MAX 99999
using namespace std;

int main() {
	int i, j, min, idx, tmp;
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (i = 0; i < 10; i++) {
		min = MAX;
		for (j = i; j < 10; j++) {
			// change min variable and save index with idx
			if (arr[j] < min) {
				min = arr[j];
				idx = j;
			}
		}
		// exchange min value with arr[j] with variable 'tmp'
		tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}

	// print modified array
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}