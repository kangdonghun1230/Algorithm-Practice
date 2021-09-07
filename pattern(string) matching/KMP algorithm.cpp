/*
* @brief ���ڿ� ��Ī �˰����� KMP ���� �н��� ���� ������ �ڵ�
* @date 2021/09/06
* @author ������
* @parameter nothing
* @return print index information
* @big O O(N(parent size) + M(pattern size))
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();

	// patternSize��ŭ 0���� �ʱ�ȭ
	vector<int> table(patternSize, 0);

	// j�� pattern array �󿡼� �����̸� table array�� ���� ä��µ� ���Ǵ� ��ġ�� ����Ű�� �����̴�.
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			// ��ġ���� �ʴ� ��� j-1�� index�� ���� table�迭�� ����Ű�� ������ �̵��մϴ�.
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			// ��ġ�ϴ� ��� table�� ��ġ�� ����Ѵ�. (������� ��ġ�ϴ� ��� �ش� index�� �̵��Ͻÿ�)
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
			// j-1 index�� ����Ű�� table�� ��ġ�� �̵�
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == m - 1) {
				// parent���� ��ġ�ϴ� pattern�� ã�� ��� index ���� �� �ٽ� Ž���� ������.
				result.push_back(i - m + 1);
				// �̹����� ������ ���ڵ� ��ġ�ϱ� ������ table[j]�� ���� ��Ž���Ѵ�.
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
������ �˴� �ܼ� ���ڿ� ��Ī �˰����� ��� �ð� ���⵵�� ����
���� ȿ�������� ���� �˰����̴�. (O(P x P)�� �ð� ���⵵)

�� �˰��� ����� �ٽ� ������ ���λ�� ���̻��� �����̰�,
�츮�� ���ؾ� �ϴ� ���� ���λ�� ���̻簡 ��ġ�ϴ� �ִ� �����Դϴ�.

���λ�� ���̻簡 ��ġ�ϴ� ������ ���� ������ ���ϰ� �Ǹ�, ���λ��
���̻簡 ��ġ�ϴ� ��쿡 ���ؼ� ����(Jump)�� ������ �� �ִٴ� ������
������ ȿ�����Դϴ�.

��, ���λ� ���̻簡 ��ġ�ϴ� ������ Ȱ���ؼ� ���� �񱳽ÿ� ���ʿ��� Ž��
�� �����ϸ� ���� ������ ���ڿ� �񱳸� �����Ͽ� �� ���� ���ڿ� �񱳰�
�����ϰ� �Ǵ� ���Դϴ�.
*/