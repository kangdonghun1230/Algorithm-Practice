/*
	Date: 2022/05/24
	Brief:
	BFS or DFS maybe
	Reference:
*/
#include <iostream>
#include <queue>
#include <cmath>

#define N_MAX 21

using namespace std;

// Fish struct
struct Fish {
	int x, y, dist;

	bool operator<(const Fish& b) const
	{
		if (dist == b.dist)
		{
			if (x != b.x)
				return x > b.x;
			else
				return y > b.y;
		}
		return dist > b.dist;
	}
};

// queue which saves the coordinates
queue<Fish> shark;

// n: size of the space, m: the number of fishes in the space
int n, m;

// up, down, left, right
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

// it represents the space information
int space[N_MAX][N_MAX];

bool inRange(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= n);
}

int BFS() {
	int baby_shark_size = 2;
	// time: 소모시간, eat: the number of fishes baby shark ate with current size
	int time = 0, eat = 0;

	while (true) {
		// feed list, fish can eat in this position
		priority_queue<Fish> feed_list;

		// this variable represents whether baby shark already visited this site or not
		vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));

		// find feed list (baby shark can eat)
		while (!shark.empty()) {
			int cur_x = shark.front().x;
			int cur_y = shark.front().y;
			int cur_dis = shark.front().dist;
			// pop from the queue
			shark.pop();

			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dx[i];
				int next_y = cur_y + dy[i];
				int next_dis = cur_dis + 1;

				if (!inRange(next_x, next_y))
					continue;

				if (visited[next_x][next_y] || space[next_x][next_y] > baby_shark_size)
					continue;

				// push this feed to feed list
				if (space[next_x][next_y] < baby_shark_size && space[next_x][next_y] != 0) {
					feed_list.push({ next_x, next_y, next_dis });
				}

				visited[next_x][next_y] = true;
				shark.push({ next_x, next_y, next_dis });
			}
		}
		// couldn't find any fish
		if (feed_list.empty()) {
			break;
		}
		Fish prior_feed = feed_list.top();
		
		if (++eat == baby_shark_size) {
			eat = 0;
			// 체급 증가
			baby_shark_size++;
		}

		space[prior_feed.x][prior_feed.y] = 0;
		// 다음 위치를 shark에 넣어준다.
		shark.push({ prior_feed.x, prior_feed.y, 0 });

		time += prior_feed.dist;
	}

	return time;
}

int main() {
	int i, j;
	cin.tie(NULL);

	cin >> n;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) 
			{
				space[i][j] = 0;
				shark.push({ i, j, 0 });
			}
		}
	}

	cout << BFS() << "\n";

	return 0;
}