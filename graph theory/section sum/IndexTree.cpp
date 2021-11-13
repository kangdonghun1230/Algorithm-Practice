/*
	Date: 2021/11/13
	Brief: Index Tree (2진 인덱스 구조를 활용하여 '구간 합' 문제를
	효과적으로 해결해줄 수 있는 자료구조.
	Reference: https://blog.naver.com/ndb796/221312822103
*/
#include <iostream>
#define NUMBER 17

using namespace std;

int tree[NUMBER];

/*
	function name: getLastBit
	
	brief:
	get the last bit of input integer type number
	we can get the last bit with operation(K & -K)
	because computer internally have 2's complement
	structure to whole datas

	return: last bit information
*/
int getLastBit(int num) {
	int lastBit;
	lastBit = (num & -num);

	return lastBit;
}
/*
	function name: update
	
	brief:
	this function update the tree array's data, with new
	value(dif means difference with current data and 
	new data)
*/
void update(int i, int dif) {
	while (i < NUMBER) {
		tree[i] += dif;
		// move to next element (LastBit만큼 이동)
		i += getLastBit(i);
	}
}
/*
	function name: sum
	
	brief:
	get the sum of 1 ~ i, move LastBit amount to forward
*/
int sum(int i) {
	int result = 0;
	while (i > 0) {
		result += tree[i];
		// move to next element subtrating the LastBit value
		i -= getLastBit(i);
	}

	return result;
}
/*
	function name: getSection
	
	brief:
	get the sum of start~end with sum function
*/
int getSection(int start, int end) {
	if (start < 0 && end >= NUMBER) return -1;
	return (sum(end) - sum(start - 1));
}

int main() {
	/*
	for (int i = 0; i <= 16; i++) {
		cout << i << "의 마지막으로 1인 비트의 위치 값: " << getLastBit(i) << endl;
	}
	*/
	for (int i = 1; i < NUMBER; i++) {
		update(i, i);
	}
	// sum of 2 ~ 5 elements sum
	cout << getSection(2, 5) << endl;
	// sum of 1 ~ 14 elements sum
	cout << getSection(1, 14) << endl;
	// subtract 2 to original element 5
	update(5, -2);
	// get the same section sum after change the element5
	cout << getSection(1, 14) << endl;

	return 0;
}