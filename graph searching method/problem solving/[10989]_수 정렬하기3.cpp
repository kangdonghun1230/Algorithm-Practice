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
Error : 변수 이름이 모호합니다. 
using namespace std에 동일한 이름의 변수가 내포되어있고
이를 코딩하는 과정에서 재정의하게 되면 어떤 변수를
지칭하는지에 대한 모호함의 문제가 발생하여 이런 문제가 발생하는 것이다.
*/