/*
	Date: 2022/04/10
	Brief:
	math problem + implementation
	Reference:
*/
#include <iostream>

using namespace std;

long long arr[6];
long long minCase1 = 51;
long long minCase2 = 51 * 3;
long long minCase3 = 51 * 2;
/*
case 1: find minimum number
case 2: {a, b, c}, { a, b, d }, { a, d, e }, { a, e, c }
		{f, b, c}, { f, b, d }, { f, d, e }, { f, e, c }

case 3: {a, b}, { a, d }, { a, e }, { a, c }
		{c, b}, { b, d }, { d, e }, { e, c }
		{f, b}, { f, d }, { f, e }, { f, c }
*/

void findMinCase2() {
	// a, b, c
	if (minCase2 > arr[0] + arr[1] + arr[2])
		minCase2 = arr[0] + arr[1] + arr[2];
	// a, b, d
	if (minCase2 > arr[0] + arr[1] + arr[3])
		minCase2 = arr[0] + arr[1] + arr[3];
	// a, d, e
	if (minCase2 > arr[0] + arr[3] + arr[4])
		minCase2 = arr[0] + arr[3] + arr[4];
	// a, e, c
	if (minCase2 > arr[0] + arr[4] + arr[2])
		minCase2 = arr[0] + arr[4] + arr[2];
	// f, b ,c
	if (minCase2 > arr[5] + arr[1] + arr[2])
		minCase2 = arr[5] + arr[1] + arr[2];
	// f, b, d
	if (minCase2 > arr[5] + arr[1] + arr[3])
		minCase2 = arr[5] + arr[1] + arr[3];
	// f, d, e
	if (minCase2 > arr[5] + arr[3] + arr[4])
		minCase2 = arr[5] + arr[3] + arr[4];
	// f, e, c
	if (minCase2 > arr[5] + arr[4] + arr[2])
		minCase2 = arr[5] + arr[4] + arr[2];
	//cout << minCase2 << "\n";
}

void findMinCase3() {
	// a, b
	if (minCase3 > arr[0] + arr[1])
		minCase3 = arr[0] + arr[1];
	// a, d
	if (minCase3 > arr[0] + arr[3])
		minCase3 = arr[0] + arr[3];
	// a, e
	if (minCase3 > arr[0] + arr[4])
		minCase3 = arr[0] + arr[4];
	// a, c
	if (minCase3 > arr[0] + arr[2])
		minCase3 = arr[0] + arr[2];
	// c, b
	if (minCase3 > arr[2] + arr[1])
		minCase3 = arr[2] + arr[1];
	// b, d
	if (minCase3 > arr[1] + arr[3])
		minCase3 = arr[1] + arr[3];
	// d, e
	if (minCase3 > arr[3] + arr[4])
		minCase3 = arr[3] + arr[4];
	// e, c
	if (minCase3 > arr[4] + arr[2])
		minCase3 = arr[4] + arr[2];
	// f, b
	if (minCase3 > arr[5] + arr[1])
		minCase3 = arr[5] + arr[1];
	// f, d
	if (minCase3 > arr[5] + arr[3])
		minCase3 = arr[5] + arr[3];
	// f, e
	if (minCase3 > arr[5] + arr[4])
		minCase3 = arr[5] + arr[4];
	// f, c
	if (minCase3 > arr[5] + arr[2])
		minCase3 = arr[5] + arr[2];
	//cout << minCase3 << "\n";
}

int main() {
	long long res = 0;
	long long n;
	int i, j;
	int idx, max = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (i = 0; i < 6; i++) {
		cin >> arr[i];
		minCase1 = (minCase1 < arr[i]) ? minCase1 : arr[i];
		max = (max > arr[i]) ? max : arr[i];
		idx = (max > arr[i]) ? idx : i;
	}

	if (n == 1) {
		for (i = 0; i < 6; i++) {
			if (i == idx) continue;
			res += arr[i];
		}
		cout << res << "\n";
		return 0;
	}

	// case 1
	res += ((n - 2) * (n - 1) * 4 + (n - 2) * (n - 2)) * minCase1;

	// case 2
	findMinCase2();
	res += minCase2 * 4;

	// case 3
	findMinCase3();
	res += minCase3 * ((n - 2) * 4 + (n - 1) * 4);

	cout << res << '\n';


	return 0;
}

/*
	한 면에 들어가는 숫자의 개수 = N * N
	
	1. 사이드에 박히지 않고, 가운데 한 개의 숫자만 표현하는 경우 -> 최솟값으로
	개수: N-2*N-1*4 + N-2*N-2

	2. 삼 면이 드러나는 경우 -> 8가지 경우의 수 중에서 최소합을 찾아라
	개수: 4개

	2.5. 바닥에서 삼 면 중 두 면이 드러나는 경우 -> 3과 통합

	3. 두 면이 드러나는 경우 -> 12가지 경우의 수 중에서 최소합을 찾아라.
	개수: N-1 * 4 + N-2 * 4개


	case 1: find minimum number
	case 2: {a, b, c}, {a, b, d}, {a, d, e}, {a, e, c}
			{f, b, c}, {f, b, d}, {f, d, e}, {f, e, c}

	case 3: {a, b}, {a, d}, {a, e}, {a, c}
			{c, b}, {b, d}, {d, e}, {e, c}
			{f, b}, {f, d}, {f, e}, {f, c}
*/