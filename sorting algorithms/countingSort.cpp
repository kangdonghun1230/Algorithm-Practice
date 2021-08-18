/*
* @brief counting sort() 개념을 익히기 위한 코드 2
* @date 2021/08/15
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O O(N)
*/
#include <iostream>

using namespace std;

int main() {
	int tmp;
	int count[6];
	int arr[30] = {
		1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
		3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
		3, 1, 4, 3, 5, 1, 2, 1, 1, 1
	};

	// initialize count array with 0
	for (int i = 1; i <= 5; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < 30; i++) {
		count[arr[i]]++;
	}

	for (int i = 1; i <= 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++)
				printf("%d ", i);
		}
	}

	return 0;
}