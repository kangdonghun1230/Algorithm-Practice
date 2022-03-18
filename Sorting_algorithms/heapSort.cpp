/*
* @brief C++ STL sort() 개념을 익히기 위한 코드 2
* @date 2021/08/12
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O N*logN (같은 시간복잡도의 algorithm 중 가장 강력하다.)
*/
#include <iostream>

using namespace std;

int num = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main() {
	// 첫번째 node부터 heapify
	for (int i = 1; i < num; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			c = root;
		} while (c != 0);
	}

	// 크기를 줄여가며 반복적으로 힙을 구성한다.
	for (int i = num - 1; i >= 0; i--) {
		int tmp = heap[0]; // 기존의 root (현재의 최댓값)
		heap[0] = heap[i];
		heap[i] = tmp;

		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			// 두 자식 중 더 큰 값을 찾는다.
			if (c < i - 1 && heap[c] < heap[c + 1])
				c++;

			// 루트보다 자식이 크다면 교환한다.
			if (c < i && heap[root] < heap[c]) {
				tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			// 한 층 아래로 내려간다.
			root = c;
		} while (c < i);
		// 현재 정렬된 node 이전까지에 대해서 reheapify를 실행해야 하기 때문이다.
	}

	for (int i = 0; i < num; i++)
		printf("%d ", heap[i]);
	printf("\n");
	return 0;
}