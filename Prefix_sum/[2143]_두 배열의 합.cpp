/*
	Date: 2022/03/21
	Brief:
	cumulative sum + binary search
	Reference:
	https://jaimemin.tistory.com/1111
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

long long arr1[MAX], arr2[MAX];
long long cumul1[MAX], cumul2[MAX];

int main() {
	int t, n, m;
	int i, j;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr1[i];
		cumul1[i] = cumul1[i - 1] + arr1[i];
	}
	cin >> m;
	for (i = 1; i <= m; i++) {
		cin >> arr2[i];
		cumul2[i] = cumul2[i - 1] + arr2[i];
	}

	vector<long long> sectionSum1, sectionSum2;

	for (i = 0; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			long long sum = cumul1[j] - cumul1[i];
			sectionSum1.push_back(sum);
		}
	}

	for (i = 0; i <= m; i++) {
		for (j = i + 1; j <= m; j++) {
			long long sum = cumul2[j] - cumul2[i];
			sectionSum2.push_back(sum);
		}
	}

	sort(sectionSum1.begin(), sectionSum1.end());
	sort(sectionSum2.begin(), sectionSum2.end());

	long long result = 0;

	for (i = 0; i < sectionSum1.size(); i++) {
		int low = lower_bound(sectionSum2.begin(), sectionSum2.end(), t - sectionSum1[i]) - sectionSum2.begin();
		int high = upper_bound(sectionSum2.begin(), sectionSum2.end(), t - sectionSum1[i]) - sectionSum2.begin();

		result += (high - low);
	}

	cout << result << "\n";

	return 0;
}