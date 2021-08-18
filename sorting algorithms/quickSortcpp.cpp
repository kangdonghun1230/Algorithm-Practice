/*
* @brief quick sort�� ������ �������� ������ ������ �ڵ��̴�.
* @date 2021/08/09
* @author ������
* @parameter nothing
* @return nothing
* @big O N*logN (���� �ð����⵵�� algirthm �� ���� �����ϴ�.)
*/
#include <stdio.h>

int num = 10;
int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* arr, int start, int end) {
	if (start >= end) {
		// ���Ұ� 1���� ��쿡 �ش��Ѵ�.
		return;
	}
	// pivot�� ù ��° ������ ����
	int key = start;
	int i = start + 1;	// ���ʺ��� ū ���� ã�� ���� index
	int j = end;		// �����ʺ��� ���� ���� ã�� ���� index
	int tmp;			// �� ������ �� ������ ���� variable

	while (i <= j) {	// ������ ������
		while (arr[i] <= arr[key])
			i++;
		// �������� ��� ���ʿ� �ִ� ���� pivot�� �ٲٱ� ������ j�� ������ �������ش�.
		while (arr[j] >= arr[key] && j > start)
			j--;

		if (i > j) {	// �������� ���
			tmp = arr[j];
			arr[j] = arr[key];
			arr[key] = tmp;
		}
		else {			// �������� �ʴ� ���
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	// �Ű��� pivot�� �������� ����, �����ʿ� ���ؼ� ���������� quick sorting �� �� �ֵ���
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
�� -> �� : pivot���� ū ���� ã�´�.
�� -> �� : pivot���� ���� ���� ã�´�.
���� �������� �Ǹ� ���ʿ� �ִ� ���� pivot�� �ٲ��ش�.
�̷��� ��ȯ�ϰ� �Ǹ�, ���� pivot ���� ���ʿ� �ִ� ���� pivot���� ���� ���� ����,
�����ʿ� �ִ� ������ ���� pivot���� ū ���� ���� �ȴ�.

��ȯ�� ���� pivot�� ����, �����ʿ� ���ؼ� pivot�� �缳���Ͽ� ����������
���� �۾��� �簳�ϸ� quick sorting�� ����ȴ�.

������, �־��� ��쿡�� N^2�� �ð����⵵�� ���� ��쵵 �߻��Ѵ�.
���� ��κ��� ��쿡�� ������ ó�����ش�. ��ȸ���� N*logN�� �䱸�ϴ� ��� Ʋ������
1, 2, 3, 4, 5, 6, 7, 8, 9, 10 �̷� ������ �̹� ���ĵ� �����͵��� quick sorting �ϴ� ��쿡
�ռ� ���ߵ� N^2�� �ð� ���⵵�� ���� �ȴ�.
*/