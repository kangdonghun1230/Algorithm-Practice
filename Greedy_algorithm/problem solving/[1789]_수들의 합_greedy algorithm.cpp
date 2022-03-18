#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 4294967295
using namespace std;

int main() {
	long long s;
	scanf("%lld", &s);

	long long result = s;
	unsigned int cnt = 0;
	for (long long i = 1; i <= MAX; i++) {
		if (result - i >= 0) {
			cnt++;
			result -= i;
		}
		else {
			printf("%d\n", cnt);
			break;
		}
	}
	return 0;
}

/*
������ ���� ���� ���� ������� �����ִ� ������ ������ Ǯ���
s�� �����ϴ� �ڿ����� ������ �ִ�� ���� �� ���� ���Դϴ�.

�׷��� ������ ������� ���� ���ϴٰ� s�� �Ѿ�� ��������
count�� ���߰� �Ǹ� ��Ȯ�� ������ ���ɴϴ�.
�ֳ��ϸ� ���� ������ ���� ū ���� 1�� ������Ű�� s ���� ����
�� �ֱ� �����Դϴ�.
*/