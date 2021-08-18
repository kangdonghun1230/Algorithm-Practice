/*
* @brief C++ STL sort() ������ ������ ���� �ڵ� 2
* @date 2021/08/12
* @author ������
* @parameter nothing
* @return nothing
* @big O N*logN (���� �ð����⵵�� algorithm �� ���� �����ϴ�.)
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
	// �� ���� data�� �ٷ�� ���� pair ���
	vector<pair<string, pair<int, int>>> v;

	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(90, 19941201)));
	v.push_back(pair<string, pair<int, int>>("���ѿ�", pair<int, int>(80, 19980322)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(100, 19980211)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(99, 19981230)));


	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
	}

	return 0;
}

/*
pair�� Ȱ���ϸ� ���� class�� �����Ͽ� ����ϴ� �ͺ��� ª�� �ڵ带 ������ �� �ִ�.
������, pair�� Ȱ���ϴ� ���� �ʹ� �����ϴٸ�, 
�׳� class�� ���� �� object�� ���� ����� �����Ͽ� ����ϴ� ���� ������ �ִ�.

���ı����� 2�� ������ ��� pair, vector�� �Բ� ����Ͽ� ������ ���α׷����� ������ ���̴�.
*/