/*
* @brief 단순 문자열 매칭 알고리즘인 KMP 알고리즘 개념에 대한 간단한 코드
* @date 2021/09/06
* @author 강동훈
* @parameter nothing
* @return print index information
* @big O O(N ^ 2)
*/
#include <iostream>
#include <string>

using namespace std;

int findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();

	for (int i = 0; i <= parentSize - patternSize; i++) {
		bool finded = true;

		for (int j = 0; j < patternSize; j++) {
			if (parent[i + j] != pattern[j]) {
				finded = false;
				break;
			}
		}
		if (finded) {
			// return index information
			return i;
		}
	}
	return -1;
}

int main() {
	string parent, pattern;
	
	cout << "Enter parent, pattern string : ";
	cin >> parent >> pattern;

	cout << findString(parent, pattern) << "번째 index에서 찾았습니다." << endl;

	return 0;
}

/*
구현하기는 쉽지만 효율적이지 못한 문자열 매칭 알고리즘입니다.
많이 사용하지 않는다.
*/