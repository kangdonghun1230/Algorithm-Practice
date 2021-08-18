/*
* @brief C++ STL sort() ������ ������ ���� �ڵ� 2
* @date 2021/08/12
* @author ������
* @parameter nothing
* @return nothing
* @big O N*logN (���� �ð����⵵�� algorithm �� ���� �����ϴ�.)
*/
#include <iostream>

using namespace std;

int num = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main() {
	// ù��° node���� heapify
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

	// ũ�⸦ �ٿ����� �ݺ������� ���� �����Ѵ�.
	for (int i = num - 1; i >= 0; i--) {
		int tmp = heap[0]; // ������ root (������ �ִ�)
		heap[0] = heap[i];
		heap[i] = tmp;

		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			// �� �ڽ� �� �� ū ���� ã�´�.
			if (c < i - 1 && heap[c] < heap[c + 1])
				c++;

			// ��Ʈ���� �ڽ��� ũ�ٸ� ��ȯ�Ѵ�.
			if (c < i && heap[root] < heap[c]) {
				tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			// �� �� �Ʒ��� ��������.
			root = c;
		} while (c < i);
		// ���� ���ĵ� node ���������� ���ؼ� reheapify�� �����ؾ� �ϱ� �����̴�.
	}

	for (int i = 0; i < num; i++)
		printf("%d ", heap[i]);
	printf("\n");
	return 0;
}