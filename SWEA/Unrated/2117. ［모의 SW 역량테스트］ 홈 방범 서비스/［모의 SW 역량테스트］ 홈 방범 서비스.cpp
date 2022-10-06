#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct Node {
	int row, col;
};
int N, M;
int map[20][20];
int used[20][20];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int bfs(int i, int j) {
	int num = 0, home = 0;
	int maxx[50] = { 0 };
	queue<Node> q;
	q.push({ i, j });
	used[i][j] = 1;
	if (map[i][j] == 1) num++;
	maxx[used[i][j]] = num;
	int nrow = 0, ncol = 0;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nrow = now.row + dr[i];
			ncol = now.col + dc[i];
			if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) continue;
			if (used[nrow][ncol] != 0) continue;
			used[nrow][ncol] += used[now.row][now.col] + 1;
			if (map[nrow][ncol] == 1) num++;
			q.push({ nrow, ncol });
			maxx[used[nrow][ncol]] = num;
		}
	}
	int cost = 0, maxhome = 0;
	for (int l = 0; l <= N*2; l++) {
		cost = l * l + (l - 1) * (l - 1);
		if(cost<=maxx[l]*M) maxhome = max(maxhome, maxx[l]);
	}
	return maxhome;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			used[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int ans = 0, home = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				home = bfs(i, j);
				ans = max(ans, home);
				init();
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}