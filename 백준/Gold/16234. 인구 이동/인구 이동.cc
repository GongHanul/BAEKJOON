#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int x, y;
};

int N, L, R, day;
int map[55][55];
int used[55][55];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };
vector<Node> v;
int sum;

void bfs(int row, int col) {
	queue<Node> q;
	q.push({ row, col });
	used[row][col] = 1;
	v.push_back({ row, col });
	sum = map[row][col];

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nrow = now.x + dr[i];
			int ncol = now.y + dc[i];
			if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) continue;
			if (used[nrow][ncol] != 0) continue;
			if (abs(map[now.x][now.y] - map[nrow][ncol]) >= L && abs(map[now.x][now.y] - map[nrow][ncol]) <= R) {
				used[nrow][ncol] = 1;
				q.push({ nrow, ncol });
				v.push_back({ nrow, ncol });
				sum += map[nrow][ncol];
			}
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			used[i][j] = 0;
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			used[i][j] = 0;
		}
	}
	day = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!used[i][j]) {
					v.clear();
					bfs(i, j);
				}
				if (v.size() > 1) {
					flag = 1;
					for (int k = 0; k < v.size(); k++) {
						map[v[k].x][v[k].y] = sum / v.size();
					}
				}
			}
		}
		if (flag) day++;
		init();
	}

	cout << day;

	return 0;
}