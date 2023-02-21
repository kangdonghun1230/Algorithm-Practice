#include <iostream>
#define MAX 100001
#define MAX_VAL 900001
#define MIN_VAL -1
using namespace std;

int n;
int dp_max[2][3];
int dp_min[2][3];

bool inRange(int x) {
	return (0 <= x && x <= 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	//memory 초과 문제를 줄여보자.
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		dp_max[1][0] = (dp_max[0][0] + x > dp_max[0][1] + x) ? dp_max[0][0] + x : dp_max[0][1] + x;
		
		dp_max[1][1] = (dp_max[0][0] + y > dp_max[0][1] + y) ? dp_max[0][0] + y : dp_max[0][1] + y;
		dp_max[1][1] = (dp_max[1][1] > dp_max[0][2] + y) ? dp_max[1][1] : dp_max[0][2] + y;

		dp_max[1][2] = (dp_max[0][1] + z > dp_max[0][2] + z) ? dp_max[0][1] + z : dp_max[0][2] + z;


		dp_min[1][0] = (dp_min[0][0] + x < dp_min[0][1] + x) ? dp_min[0][0] + x : dp_min[0][1] + x;

		dp_min[1][1] = (dp_min[0][0] + y < dp_min[0][1] + y) ? dp_min[0][0] + y : dp_min[0][1] + y;
		dp_min[1][1] = (dp_min[1][1] < dp_min[0][2] + y) ? dp_min[1][1] : dp_min[0][2] + y;

		dp_min[1][2] = (dp_min[0][1] + z < dp_min[0][2] + z) ? dp_min[0][1] + z : dp_min[0][2] + z;


		//한 칸 내린다.
		for (int j = 0; j < 3; j++) {
			dp_max[0][j] = dp_max[1][j];
			dp_min[0][j] = dp_min[1][j];
		}
	}

	int max_res = MIN_VAL, min_res = MAX_VAL;
	for (int j = 0; j < 3; j++) {
		max_res = (max_res > dp_max[1][j]) ? max_res : dp_max[1][j];
		min_res = (min_res < dp_min[1][j]) ? min_res : dp_min[1][j];
	}

	cout << max_res << " " << min_res;

	return 0;
}