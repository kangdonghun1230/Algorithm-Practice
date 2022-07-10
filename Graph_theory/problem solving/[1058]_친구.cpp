/*
	Date: 2022/07/10
	Brief:
	data structure, graph searching, graph theory
	Reference:
*/
#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int n;

vector<int> friendMap[MAX];

int main() {
	int i, j, k;

	cin.tie(NULL);
	cin >> n;

	for (i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		for (j = 0; j < n; j++) {
			if (tmp[j] == 'Y') {
				// graph mapping
				friendMap[i].push_back(j);
			}
			else
				continue;
		}
	}

	int res = 0;

	for (i = 0; i < n; i++) {
		int tmp = 0;
		bool visited[MAX] = {0, };

		visited[i] = true;
		for (j = 0; j < friendMap[i].size(); j++) {
			visited[friendMap[i][j]] = true;
			tmp++;
		}

		for (j = 0; j < friendMap[i].size(); j++) {
			int adjFriend = friendMap[i][j];

			for (k = 0; k < friendMap[adjFriend].size(); k++) {
				if (!visited[friendMap[adjFriend][k]]) {
					visited[friendMap[adjFriend][k]] = true;
					tmp++;
				}
			}
		}

		// find maximum friend2 with conditional operator
		res = (res < tmp) ? tmp : res;
	}

	cout << res << "\n";
	
	return 0;
}