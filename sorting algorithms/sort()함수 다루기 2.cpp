/*
* @brief C++ STL sort() 개념을 익히기 위한 코드 2
* @date 2021/08/12
* @author 강동훈
* @parameter nothing
* @return nothing
* @big O N*logN (같은 시간복잡도의 algorithm 중 가장 강력하다.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main() {
	// 한 쌍의 data를 다루기 위해 pair 사용
	vector<pair<string, pair<int, int>>> v;

	v.push_back(pair<string, pair<int, int>>("나동빈", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("이태일", pair<int, int>(90, 19941201)));
	v.push_back(pair<string, pair<int, int>>("박한울", pair<int, int>(80, 19980322)));
	v.push_back(pair<string, pair<int, int>>("공혜원", pair<int, int>(100, 19980211)));
	v.push_back(pair<string, pair<int, int>>("강동훈", pair<int, int>(99, 19981230)));


	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
	}

	return 0;
}

/*
pair를 활용하면 직접 class를 정의하여 사용하는 것보다 짧게 코드를 구성할 수 있다.
하지만, pair를 활용하는 것이 너무 복잡하다면, 
그냥 class를 선언 후 object를 각각 만들어 정렬하여 사용하는 것이 좋을수 있다.

정렬기준이 2개 이하인 경우 pair, vector를 함께 사용하여 빠르게 프로그래밍이 가능할 것이다.
*/