/*
	Date: 2022/03/22
	Brief:
	max heap implementation code.
	Reference:
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

using namespace std;

class Heap {
public:
	void init() {
		heap_count = 0;
	}
	int size() {
		return heap_count;
	}
	void swap(int* a, int* b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
	void push(int x) {
		heap[++heap_count] = x;

		int child = heap_count;
		int parent = child / 2;
		// max heap�� ���缭 �˸��� ��ġ�� node�� ��ġ�� �����ϴ� ����
		while (child > 1 && heap[child] > heap[parent]) {
			swap(&heap[parent], &heap[child]);
			child = parent;
			parent /= 2;
		}
	}
	int pop() {
		// head's index is 1
		int result = heap[1];
		// head�� ���ҿ� ������ ���� ��ġ�� �ٲٰ�, count�� 1 �ٿ��ش�.
		swap(&heap[1], &heap[heap_count]);
		heap_count--;

		int parent = 1;
		int child = parent * 2;
		// choose bigger child.
		if (child + 1 <= heap_count) {
			child = (heap[child] < heap[child + 1]) ? child + 1 : child;
		}
		// reheapify
		while (child <= heap_count && heap[child] > heap[parent]) {
			swap(&heap[child], &heap[parent]);
			parent = child;
			child *= 2;

			if (child + 1 <= heap_count) {
				child = (heap[child] < heap[child + 1]) ? child + 1 : child;
			}
		}
		// return the original element of the heap.
		return result;
	}
private:
	int heap[HEAP_SIZE];
	int heap_count = 0; // heap ������ ������ ������ ǥ���ϴ� �����̴�.
};

int main() {
	Heap heap;
	int arr[ARRAY_SIZE + 1];
	int res[ARRAY_SIZE + 1];

	srand(time(NULL));

	for (int i = 1; i <= ARRAY_SIZE; i++) {
		arr[i] = rand() % 2000 + 1;
		res[i] = arr[i];
	}

	for (int i = 1; i <= ARRAY_SIZE; i++) {
		heap.push(arr[i]);
	}
	for (int i = 1; i <= ARRAY_SIZE; i++) {
		arr[i] = heap.pop();
	}

	sort(res + 1, res + ARRAY_SIZE + 1, greater<int>());
	bool isEqual = true;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (res[i] != arr[i]) {
			isEqual = false;
			break;
		}
	}
	/*
	for (int i = 1; i <= ARRAY_SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	*/
	/*
	for (int i = 1; i <= ARRAY_SIZE; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
	*/
	if (isEqual) {
		cout << "Right!\n";
	}
	else {
		cout << "Error!\n";
	}

	return 0;
}