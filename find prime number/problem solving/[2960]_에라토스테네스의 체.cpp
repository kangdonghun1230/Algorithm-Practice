#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 1001
int n, k, result;
int a[MAX];

void primeNumberSieve() {
	for (int i = 2; i <= n; i++) {
		a[i] = i;
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) continue;
		for (int j = i; j <= n; j += i) {
			if (a[j] == 0) continue;
			a[j] = 0;
			cnt++;
			if (cnt == k) {
				printf("%d\n", j);
				return;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);

	primeNumberSieve();

	return 0;
}