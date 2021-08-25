#include <iostream>

using namespace std;

int num ;
int heap[10];

// 하향식 reheapify
void heapify(int idx) {
	// left child node
	int c = 2 * idx + 1;
	int tmp;

	// choose bigger chlid node
	if (c < num - 1 && heap[c] < heap[c + 1]) {
		c++;
	}

	// if child node is bigger than parent node
	if (heap[idx] < heap[c]) {
		tmp = heap[idx];
		heap[idx] = heap[c];
		heap[c] = tmp;
	}
	// num / 2 까지 수행
	if (c <= num / 2) heapify(c);

	return;
}

int main() {
	int tmp, i, j;
	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> heap[i];
	}

	// make heap structure
	for (i = num / 2; i >= 0; i--) {
		heapify(i);
	}

	for (i = num - 1; i >= 0; i--) {
		for (j = 0; j < num; j++) {
			cout << heap[j] << ' ';
		}
		cout << "\n";

		tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;

		int root = 0;
		int c = 1;
		do {
			// c is left child of root
			c = 2 * root + 1;
			if (c < i - 1 && heap[c] < heap[c + 1])
				c++;
			if (c < i && heap[root] < heap[c]) {
				tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			root = c;
		} while (c < i);

	}

	return 0;
}