/*
	Date: 2022/01/06
	Brief:
	BitMask is the technique which is masking bit.
	Masking bit means processing binary bit with &, |
	operations.
*/
#include <iostream>

using namespace std;

/*
	function name: show
	brief:
	print the integer number in binary number
*/
void show(int* a) {
	for (int i = 32; i > 0; i--) {
		// print the each binary position of number
		cout << ((*a & (1 << i - 1)) ? 1 : 0);
	}
	return;
}

/*
	function name: init
	brief:
	initialize all the bit points with 0.
	Exclude all of the members
*/
void init(int* a) {
	*a = 0;
}
/*
	function name: full
	brief:
	include all of the members
*/
void full(int* a) {
	// make whole bit value to 1
	*a = -1;
}
/*
	function name: drop
	brief:
	delete particular member(i th)
*/
void drop(int* a, int i) {
	*a &= ~(1 << i); // delete i th member
}
/*
	function name: set
	brief:
	insert particular member(i th)
*/
void set(int* a, int i) {
	*a |= (1 << i); // set i th member
}
/*
	function name: isSet
	brief:
	check the status of ith member
*/
bool isSet(int* a, int i) {
	return ((*a & (1 << i)) ? true : false);
}
/*
	function name: toggle
	brief:
	toggle particular member
*/
void toggle(int* a, int i) {
	*a ^= (1 << i); // on->off, off->on
}
/*
	function name: getLast
	brief:
	get the last element of integer
*/
int getLast(int* a) {
	// -a : 2's complement of a (inv a + 1)
	return (*a & -*a);
}
/*
	function name: dropLast
	brief:
	delete the last element
*/
void dropLast(int* a) {
	*a &= (*a - 1);
}
int main() {
	int a;
	init(&a);
	cout << "모든 원소 삭제: "; show(&a);
	cout << endl;

	full(&a);
	cout << "모든 원소 포함: "; show(&a);
	cout << endl;

	drop(&a, 3);
	cout << "Delete 3rd index element: "; show(&a);
	cout << endl;

	cout << "Check the 3rd index element: " << isSet(&a, 3);
	cout << endl;

	drop(&a, 4);
	cout << "Delete 4th index element: "; show(&a);
	cout << endl;

	cout << "Check the 4th index element: " << isSet(&a, 4);
	cout << endl;

	drop(&a, 5);
	cout << "Delete 5th index element: "; show(&a);
	cout << endl;

	set(&a, 5);
	cout << "Insert 5th index element: "; show(&a);
	cout << endl;

	toggle(&a, 5);
	cout << "Toggle 5th index element: "; show(&a);
	cout << endl;

	cout << "Check the 5th index element: " << isSet(&a, 5);
	cout << endl;

	dropLast(&a);
	dropLast(&a);
	dropLast(&a);
	cout << "Delete last 3 elements: "; show(&a);
	cout << endl;

	cout << "Get last element: " << getLast(&a);
	cout << endl;
	return 0;
}