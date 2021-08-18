/*
* @brief merge sort�� ������ �������� ������ ������ �ڵ��̴�.
* @date 2021/08/11
* @author ������
* @parameter nothing
* @return nothing
* @big O N*logN (���� �ð����⵵�� algorithm �� ���� �����ϴ�.)
*/
#include <stdio.h>
#define Num 8

int sorted[8]; // ���� �迭�� �ݵ�� ���� ������ ���� (���ʿ��� �޸� ����� ����)

// ������, �߰���, ������ argument�� �޴´�.
void merge(int arr[], int m, int mid, int n) {
	int i = m;
	int j = mid + 1;
	// k�� sorted array�� index�� �ǹ��Ѵ�.
	int k = m;
	// ���� ������� �迭�� ����
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
	// i or j�� ���� ���� �������� ���� ó���� �ϴ� �κ�
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
	// ���ĵ� �迭�� �����ϴ� ����
	for (int t = m; t <= n; t++) {
		arr[t] = sorted[t];
	}
}
/*
mergeSort �Լ��� ��������� ����Ǳ� ������
�迭�� ���Ұ� ���ʴ�� ���ĵǸ� ��������.
*/
void mergeSort(int arr[], int m, int n) {
	// ũ�Ⱑ 1���� ū ���
	if (m < n) {
		int mid = (m + n) / 2;
		// mid �������� �翷 ������ �� merge�Ѵ�.
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
�ϴ� ������ �ɰ��� ���߿� ���ϴ� algorithm

quick sort ���� �������� ������,
n log n�� �ð����⵵�� �����ϴ� algorithm�̴�.

�����ϱ� ���� ���� ������ �迭�� �ϳ� �����ؾ� �ϱ� ������
�޸𸮸� ���� �����ϱ� ������,
�ð� ���⵵�� �����Ѵٴ� ������ ���� algorithm�̴�.
*/