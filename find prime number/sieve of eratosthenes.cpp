#include <stdio.h>
#include <math.h>

int number = 100000;
int a[100001];

void primeNumberSieve() {
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number; j += i) {
			a[j] = 0;
		}
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] != 0) printf("%d ", a[i]);
	}

}

int main(void) {
	primeNumberSieve();

	return 0;
}

/*
임의의 수를 소수판별 한다고 하였을 때, 해당 수가 소수이든 아니든
어떤 두 수의 곱으로써 표현할 수 있기 때문에 이를 이용하여
N / 2의 시간 복잡도를 갖는 소수판별 함수를 만들 수 있습니다.

여기에 여러 수의 소수를 판별할 때 더 효율적으로 진행하기 위해
에라토스테네스의 체 알고리즘을 적용합니다.

에라토스테네스의 체 알고리즘은 2부터(2는 본인을 제외) 자신의 배수에
해당하는 수를 지워가면서 소수가 아닌 수를 거르는 형태로 소수를 판별할
수 있는 배열을 만들어냅니다.
*/