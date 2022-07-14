/*
	Date: 2022/07/14
	Brief:
	Implementation + BFS
	Reference:
*/
#include <iostream>
#include <vector>
#include <queue>

#define MAX 51

using namespace std;

int n, m;
bool cantLie[MAX];
// ����� ������ ��Ƽ�� ������ ����
vector<int> memberInfo[MAX];
// ��Ƽ�� ������ ����� ������ ����
vector<int> partyInfo[MAX];

int main() {
	cin.tie(NULL);
	cin >> n >> m;

	int num;
	cin >> num;

	queue<int> q;

	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;

		cantLie[tmp] = true;
		q.push(tmp);
	}
	// ������ �ƴ� ����� ��� �Է¹޴� step
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;

		for (int j = 0; j < tmp; j++) {
			int party_member;
			cin >> party_member;
			// party member�� ������ party ������ �Է�
			memberInfo[party_member].push_back(i);
			partyInfo[i].push_back(party_member);
		}
	}

	// ������ ���ؾ� �ϴ� ����� ����� �ۼ��ϴ� step
	while (!q.empty()) {
		int lieMember = q.front();
		q.pop();

		for (int i = 0; i < memberInfo[lieMember].size(); i++) {
			int partyNum = memberInfo[lieMember][i];

			for (int j = 0; j < partyInfo[partyNum].size(); j++) {
				// ������ ���ؾ� �ϴ� ���� ���
				int nextMember = partyInfo[partyNum][j];
				// �̹� ���� ����� ��� skip
				if (cantLie[nextMember])
					continue;
				// ���� ����� ������ ���ؾ��ϴ� ��� ��ܿ� �߰�
				cantLie[nextMember] = true;
				q.push(nextMember);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < m; i++) {
		bool canLie = true;

		for (int j = 0; j < partyInfo[i].size(); j++) {
			int partyMember = partyInfo[i][j];
			if (cantLie[partyMember])
				canLie = false;
		}
		// ������ �ƴ� ��ܿ� ���Ե� �ο� ���� ��� count++
		if (canLie) res++;
	}
	cout << res << "\n";

	return 0;
}

// ---------------------- union find Ǯ�� ------------------ //
#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int n, m, k;
int parents[MAX];
vector<int> cantLie;
// ��Ƽ�� ������ �ο��� ������ ����
vector<int> partyInfo[MAX];

int Find(int x) {
	if (parents[x] == x) return x;
	else return Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	// ���� ���� �θ��
	if (x < y) parents[y] = x;
	else parents[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	cin >> k;

	while (k--) {
		int num;
		cin >> num;
		cantLie.push_back(num);
	}

	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;

		int prev_party_member;
		cin >> prev_party_member;
		partyInfo[i].push_back(prev_party_member);

		for (int j = 1; j < tmp; j++) {
			int party_member;
			cin >> party_member;

			Union(prev_party_member, party_member);
			prev_party_member = party_member;

			partyInfo[i].push_back(party_member);
		}
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		// ������ ��� ����� ���� �ٱ� �ӿ� �ִ�.
		int party_member = partyInfo[i][0];

		bool canLie = true;

		for (int j = 0; j < cantLie.size(); j++) {
			if (Find(party_member) == Find(cantLie[j]))
				canLie = false;
		}
		if (canLie)
			res++;
	}
	cout << res << endl;
	return 0;
}