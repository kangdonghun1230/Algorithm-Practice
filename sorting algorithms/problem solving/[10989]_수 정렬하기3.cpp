#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[10001];

int main() {
	int N, num;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		cnt[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}

/*
Error : ���� �̸��� ��ȣ�մϴ�. 
using namespace std�� ������ �̸��� ������ �����Ǿ��ְ�
�̸� �ڵ��ϴ� �������� �������ϰ� �Ǹ� � ������
��Ī�ϴ����� ���� ��ȣ���� ������ �߻��Ͽ� �̷� ������ �߻��ϴ� ���̴�.
*/