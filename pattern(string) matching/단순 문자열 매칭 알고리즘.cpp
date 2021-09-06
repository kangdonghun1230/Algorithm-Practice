/*
* @brief �ܼ� ���ڿ� ��Ī �˰����� KMP �˰��� ���信 ���� ������ �ڵ�
* @date 2021/09/06
* @author ������
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

	cout << findString(parent, pattern) << "��° index���� ã�ҽ��ϴ�." << endl;

	return 0;
}

/*
�����ϱ�� ������ ȿ�������� ���� ���ڿ� ��Ī �˰����Դϴ�.
���� ������� �ʴ´�.
*/