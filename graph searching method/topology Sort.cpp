/*
* @brief topology sort(���� ����) ������ ���� �ڵ�
* @date 2021/08/30
* @author ������
* @parameter nothing
* @return print result array
* @big O O(V + E)
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

// inDegree : �������� information
// n : the number of nodes
int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	// ���� ���� 0�� node, queue�� ����
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// ���� ������ ������ ����Ƿ��� N���� ��带 �湮�߾�� �Ѵ�.
	for (int i = 1; i <= n; i++) {
		// ��� ��带 �湮�����ʰ� Ž���� ����Ǵ� ��� -> ����Ŭ �߻��� �ǹ�
		if (q.empty()) {
			printf("����Ŭ �߻�\n");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}

int main() {
	n = 7;

	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;

	a[2].push_back(3);
	inDegree[3]++;

	a[3].push_back(4);
	inDegree[4]++;

	a[4].push_back(6);
	inDegree[6]++;

	a[5].push_back(6);
	inDegree[6]++;

	a[6].push_back(7);
	inDegree[7]++;

	topologySort();

	return 0;
}

/*
topology sort(���� ����)�� '������ �������ִ� �۾�'��
������ �� �� ������ �����ϱ� ���� ����ϴ� algorithm�Դϴ�.

���������� ���������� �����ϸ� �Ǳ� ������, ���س� �� ����
���� ���� ���� ������ �� �ֽ��ϴ�.

���� ���� ������ DAG(Directed Acyclic Graph)���� ���� �����մϴ�.
�̴� cycle�� �߻����� �ʴ� �׷����� �ǹ��մϴ�. 
(cycle�� �߻��ϴ� ��� ���� ������ �Ұ����մϴ�.)

���� ����:
1. ���� ������ 0�� ������ ť�� �����Ѵ�.
2. ť���� ���Ҹ� ���� ����� ��� ������ �����Ѵ�.
3. ���� ���� �� ���������� 0�� �� ������ ť�� ����
4. ť�� �� ������ 2 ~ 3�� ������ �ݺ�. ��� ���Ҹ� �湮�ϱ� ����
ť�� ����ִٸ� -> ����Ŭ�� �����ϴ� ��, ��� ���Ҹ� �湮�ߴٸ� -> ť����
������ ������ ���� ������ ����̴�.
*/