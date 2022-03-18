/*
* @brief 라빈 카프 알고리즘 개념 코드
* @date 2021/09/09
* @author 강동훈
* @parameter string
* @return print matching index information
* @big O O(1)
*/
#include <iostream>

using namespace std;

void rabinKarp(string parent, string pattern) {
	int parentSize = parent.size(), patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, pow = 1;

	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				// index(patternSize - 1) means last element of pattern string (sub parent string)
				parentHash += parent[patternSize - 1 - j] * pow;
				patternHash += pattern[patternSize - 1 - j] * pow;
				// Do not multipy 2 to pow at last because we will keep using this value.
				if (j < patternSize - 1) pow *= 2;
			}
		}
		else {
			// new parent hash = 2 * (original parent hash - original first element * pow) - new element
			parentHash = 2 * (parentHash - parent[i - 1] * pow) + parent[i + patternSize - 1];
		}

		if (parentHash == patternHash) {
			bool finded = true;

			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j])
					finded = false;
			}

			if (finded) {
				printf("%d번째에서 발견!\n", i + 1);
			}
		}
	}
	return;
}

int main() {
	string parent = "abcababacabababadabac";
	string pattern = "abab";

	rabinKarp(parent, pattern);

	return 0;
}
/*
라빈 카프 알고리즘 :
항상 빠르지는 않지만 일반적인 경우 빠르게 동작하는 간단한 구조의
문자열 매칭 알고리즘이다.

라빈 카프 알고리즘은 해시(Hash) 기법을 사용한다. 해시 기법은 긴 데이터를
그것을 상징하는 짧은 데이터로 바꾸어지는 기법을 의미한다.

해시 알고리즘의 경우 연산 속도가 O(1)에 달한다는 엄청난 장점이 있다.

해시 값을 계산하는 과정에서 overflow가 발생하는 것을 방지하기 위해
modulation을 진행하는 경우가 있지만, overflow가 발생한다 하더라도
parent, pattern이 같은 값을 가지며 overflow가 발생하기 때문에, 해당
알고리즘에서는 별 문제가 없습니다.

하지만 안정적인 프로그램을 위해서는 나머지 연산(MOD)를 입히는 것을 추천!
*/