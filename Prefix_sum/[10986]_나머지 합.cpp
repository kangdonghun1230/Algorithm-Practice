#include <iostream>
#define MAX 1000001

using namespace std;

int n, m;

long long moduloCnt[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	long long curCumulativeSum = 0;

	for (int i = 0; i < n; i++) {
		int curNum;
		cin >> curNum;

		curCumulativeSum += curNum;

		// ��������� ���� �������� m�� ���� ��ⷯ ������ �����ϰ�
		// ������ ���� �ε����� �ϴ� �迭�� ��++
		moduloCnt[curCumulativeSum % m]++;
	}

	// �������� 0�� ������� 0 ~ i������ ���� ���� ��쵵 ������ ���� �ǹ��Ѵ�.
	long long resCnt = moduloCnt[0];

	for (int i = 0; i < m; i++) {
		// n���� �������� ���� = n(n-1)/2 ��(=nC2)�� ������ ź������ �ǹ�
		resCnt += (moduloCnt[i] * (moduloCnt[i] - 1)) / 2;
	}

	cout << resCnt;

	return 0;
}

/*
* �������� ����� (prefixSum[i] - prefixSum[j])�� ����Ѵ�.
* m���� ������ �������� ���� i ~ j�� ���� (prefixSum[i] - prefixSum[j]) % m == 0
* �ϳ��� �캯���� �ѱ�� prefixSum[i] % m == prefixSum[j] % m�� �ȴ�.
* ���� �츮�� �������� ������ ���� �ָ��ϸ� �ȴ�.
* �������� ���� ������ �������� ���ϸ� m�� ���� ��ⷯ ���� ����� 0�� ���̴�.
* 
* �츮�� ���� �ֵ��� �����ϴ� ����� ���� ����ϸ� �ȴ�.
*/