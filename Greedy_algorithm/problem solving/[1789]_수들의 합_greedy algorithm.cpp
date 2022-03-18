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
어차피 가장 작은 수의 순서대로 더해주는 식으로 문제를 풀어야
s를 구성하는 자연수의 개수를 최대로 해줄 수 있을 것입니다.

그렇기 때문에 순서대로 수를 더하다가 s를 넘어가는 구간에서
count를 멈추게 되면 정확한 개수가 나옵니다.
왜냐하면 현재 더해진 가장 큰 수를 1씩 증가시키면 s 값을 만들
수 있기 때문입니다.
*/