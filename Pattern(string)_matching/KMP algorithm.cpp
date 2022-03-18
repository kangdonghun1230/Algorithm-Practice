/*
* @brief 문자열 매칭 알고리즘인 KMP 개념 학습을 위한 간단한 코드
* @date 2021/09/06
* @author 강동훈
* @parameter nothing
* @return print index information
* @big O O(N(parent size) + M(pattern size))
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();

	// patternSize만큼 0으로 초기화
	vector<int> table(patternSize, 0);

	// j는 pattern array 상에서 움직이며 table array의 값을 채우는데 사용되는 위치를 가리키는 변수이다.
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			// 일치하지 않는 경우 j-1의 index에 대해 table배열이 가리키는 곳으로 이동합니다.
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			// 일치하는 경우 table에 위치를 기록한다. (여기까지 일치하는 경우 해당 index로 이동하시오)
			table[i] = ++j;
		}
	}
	return table;
}

vector<int> kmp(string parent, string pattern) {
	vector<int> result;
	// get table info from makeTable function
	auto table = makeTable(pattern);

	int n = parent.size(), m = pattern.size(), j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			// j-1 index가 가리키는 table의 위치로 이동
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == m - 1) {
				// parent에서 일치하는 pattern을 찾은 경우 index 저장 후 다시 탐색을 나선다.
				result.push_back(i - m + 1);
				// 이번에는 마지막 문자도 일치하기 때문에 table[j]로 향해 재탐색한다.
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
	return result;
}


int main() {
	string parent = "abcababaabc";
	string pattern = "abc";

	auto result = kmp(parent, pattern);

	cout << "matched size : " << result.size() << endl;

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}

/*
기존에 알던 단순 문자열 매칭 알고리즘의 경우 시간 복잡도의 낭비가
심해 효율적이지 못한 알고리즘이다. (O(P x P)의 시간 복잡도)

이 알고리즘에 적용된 핵심 개념은 접두사와 접미사의 개념이고,
우리가 구해야 하는 것은 접두사와 접미사가 일치하는 최대 길이입니다.

접두사와 접미사가 일치하는 구간에 대한 정보를 구하게 되면, 접두사와
접미사가 일치하는 경우에 한해서 점프(Jump)를 수행할 수 있다는 점에서
굉장히 효율적입니다.

즉, 접두사 접미사가 일치하는 정보를 활용해서 다음 비교시에 불필요한 탐색
을 방지하며 더욱 빠르게 문자열 비교를 진행하여 더 빠른 문자열 비교가
가능하게 되는 것입니다.
*/