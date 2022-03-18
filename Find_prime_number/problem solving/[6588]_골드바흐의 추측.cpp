#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1000001

using namespace std;

int a[MAX];

void SieveOfEratostenes() {
	//a[0] = 1; //������ 0�� �������� ��쿡�� �Ҽ��� �ƴ� ¦�� + 0�� ��Ȳ�̱� ������ ���� ����� �ʿ� ����.
	a[1] = 1;

	for (int i = 2; i <= MAX; i++) {
		for (int j = i * 2; j <= MAX; j += i) {
			if (a[j] == 1) continue;
			else a[j] = 1;
		}
	}
	return;
}

int main() {
	int n;

	SieveOfEratostenes();

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		bool finded = false;
		// ���� ��� �߿��� b-a�� ���� ū ��츦 ����ؾ� �ϱ� ������ �ڿ������� �õ��غ���. (������ �ݸ� �������� ����� �ߺ��Ǳ� ������ �������)
		for (int i = n; i >= n / 2; i--) {
			// i�� n - i�� ��� �Ҽ����?
			if (a[i] == 0 && a[n - i] == 0) {
				printf("%d = %d + %d\n", n, n - i, i);
				finded = true;
				break;
			}
		}
		
		if (!finded) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}

	return 0;
}