/*
* @brief ��� ī�� �˰��� ���� �ڵ�
* @date 2021/09/09
* @author ������
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
				printf("%d��°���� �߰�!\n", i + 1);
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
��� ī�� �˰��� :
�׻� �������� ������ �Ϲ����� ��� ������ �����ϴ� ������ ������
���ڿ� ��Ī �˰����̴�.

��� ī�� �˰����� �ؽ�(Hash) ����� ����Ѵ�. �ؽ� ����� �� �����͸�
�װ��� ��¡�ϴ� ª�� �����ͷ� �ٲپ����� ����� �ǹ��Ѵ�.

�ؽ� �˰����� ��� ���� �ӵ��� O(1)�� ���Ѵٴ� ��û�� ������ �ִ�.

�ؽ� ���� ����ϴ� �������� overflow�� �߻��ϴ� ���� �����ϱ� ����
modulation�� �����ϴ� ��찡 ������, overflow�� �߻��Ѵ� �ϴ���
parent, pattern�� ���� ���� ������ overflow�� �߻��ϱ� ������, �ش�
�˰��򿡼��� �� ������ �����ϴ�.

������ �������� ���α׷��� ���ؼ��� ������ ����(MOD)�� ������ ���� ��õ!
*/