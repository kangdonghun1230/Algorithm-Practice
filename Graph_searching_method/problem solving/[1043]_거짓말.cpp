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
// 멤버가 참여한 파티의 정보를 저장
vector<int> memberInfo[MAX];
// 파티에 참여한 멤버의 정보를 저장
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
	// 진실을 아는 멤버의 명단 입력받는 step
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;

		for (int j = 0; j < tmp; j++) {
			int party_member;
			cin >> party_member;
			// party member가 참여한 party 정보를 입력
			memberInfo[party_member].push_back(i);
			partyInfo[i].push_back(party_member);
		}
	}

	// 진실을 말해야 하는 멤버의 명단을 작성하는 step
	while (!q.empty()) {
		int lieMember = q.front();
		q.pop();

		for (int i = 0; i < memberInfo[lieMember].size(); i++) {
			int partyNum = memberInfo[lieMember][i];

			for (int j = 0; j < partyInfo[partyNum].size(); j++) {
				// 진실을 말해야 하는 다음 멤버
				int nextMember = partyInfo[partyNum][j];
				// 이미 진실 명단인 경우 skip
				if (cantLie[nextMember])
					continue;
				// 다음 멤버를 진실을 말해야하는 멤버 명단에 추가
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
		// 진실을 아는 명단에 포함된 인원 없는 경우 count++
		if (canLie) res++;
	}
	cout << res << "\n";

	return 0;
}

// ---------------------- union find 풀이 ------------------ //
#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int n, m, k;
int parents[MAX];
vector<int> cantLie;
// 파티에 참여한 인원의 정보를 저장
vector<int> partyInfo[MAX];

int Find(int x) {
	if (parents[x] == x) return x;
	else return Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	// 작은 것이 부모로
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
		// 어차피 모든 멤버는 같은 줄기 속에 있다.
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