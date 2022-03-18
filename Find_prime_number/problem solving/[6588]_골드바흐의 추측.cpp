#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1000001

using namespace std;

int a[MAX];

void SieveOfEratostenes() {
	//a[0] = 1; //어차피 0과 더해지는 경우에는 소수가 아닌 짝수 + 0의 상황이기 때문에 굳이 명시할 필요 없음.
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
		// 여러 방법 중에서 b-a가 가장 큰 경우를 출력해야 하기 때문에 뒤에서부터 시도해본다. (어차피 반만 돌려봐도 결과는 중복되기 때문에 상관없음)
		for (int i = n; i >= n / 2; i--) {
			// i와 n - i가 모두 소수라면?
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