#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int d[MAX];
int arr[MAX];

void dp(int n) {
	int result;
	
	result = arr[0];
	d[0] = arr[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(arr[i], d[i - 1] + arr[i]);
		result = max(result, d[i]);
	}
	printf("%d\n", result);
	return;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp(n);

	return 0;
}