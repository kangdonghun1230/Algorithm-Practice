/*
	Date: 2022/03/21
	Brief:
	binary search를 위한 직접 구현한
	lower_bound, upper_bound function
	Reference:
	https://blockdmask.tistory.com/168
*/
#include <iostream>
#include <algorithm>

using namespace std;

int my_lower_bound(int* arr, int n, int key) {
	int start = 0;
	int end = n;

	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (arr[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end + 1;
}

int my_upper_bound(int* arr, int n, int key) {
	int start = 0;
	int end = n;

	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (arr[mid] <= key) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	return end + 1;
}


int main() {
	int arr[10] = { 1, 2, 4, 5, 6, 6, 7, 7, 7, 9 };

	cout << "lower_bound(6) : " << my_lower_bound(arr, 10, 6) << endl;
	cout << "lower_bound(7) : " << my_lower_bound(arr, 10, 7) << endl;
	cout << "lower_bound(8) : " << my_lower_bound(arr, 10, 8) << endl;
	cout << "lower_bound(9) : " << my_lower_bound(arr, 10, 9) << endl;

	cout << "upper_bound(6) : " << my_upper_bound(arr, 10, 6) << endl;
	cout << "upper_bound(7) : " << my_upper_bound(arr, 10, 7) << endl;
	cout << "upper_bound(8) : " << my_upper_bound(arr, 10, 8) << endl;
	cout << "upper_bound(9) : " << my_upper_bound(arr, 10, 9) << endl;

	return 0;
}