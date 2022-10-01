#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int row, col;
};

int N, M, R, C, L;
int map[50][50];
int used[50][50];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int ans;

int check(int row, int col, int nrow, int ncol) {
	if (map[row][col] == 1) {
		if (row - nrow == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 4 || map[nrow][ncol] == 7)) return 1;
		if (nrow - row == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 5 || map[nrow][ncol] == 6)) return 1;
		if (col - ncol == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 6 || map[nrow][ncol] == 7)) return 1;
		if (ncol - col == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 4 || map[nrow][ncol] == 5)) return 1;
	}
	else if (map[row][col] == 2) {
		if (abs(col - ncol) == 1 && map[nrow][ncol] != 0) return 1;
		if (row - nrow == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 4 || map[nrow][ncol] == 7)) return 1;
		if (nrow - row == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 5 || map[nrow][ncol] == 6)) return 1;
	}
	else if (map[row][col] == 3) {
		if (abs(row - nrow) == 1 && map[nrow][ncol] != 0) return 1;
		if (col - ncol == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 6 || map[nrow][ncol] == 7)) return 1;
		if (ncol - col == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 4 || map[nrow][ncol] == 5)) return 1;
	}
	else if (map[row][col] == 4) {
		if ((nrow - row == 1 && map[nrow][ncol] != 0) || (col - ncol == 1 && map[nrow][ncol] != 0)) return 1;
		if (row - nrow == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 4 || map[nrow][ncol] == 7)) return 1;
		if (ncol - col == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 4 || map[nrow][ncol] == 5)) return 1;
	}
	else if (map[row][col] == 5) {
		if ((row - nrow == 1 && map[nrow][ncol] != 0) || (col - ncol == 1 && map[nrow][ncol] != 0)) return 1;
		if (nrow - row == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 5 || map[nrow][ncol] == 6)) return 1;
		if (ncol - col == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 5 || map[nrow][ncol] == 4)) return 1;
	}
	else if (map[row][col] == 6) {
		if ((row - nrow == 1 && map[nrow][ncol] != 0) || (ncol - col == 1 && map[nrow][ncol] != 0)) return 1;
		if (nrow - row == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 5 || map[nrow][ncol] == 6)) return 1;
		if (col - ncol == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 6 || map[nrow][ncol] == 7)) return 1;
	}
	else if (map[row][col] == 7) {
		if ((nrow - row == 1 && map[nrow][ncol] != 0) || (ncol - col == 1 && map[nrow][ncol] != 0)) return 1;
		if (row - nrow == 1 && (map[nrow][ncol] == 3 || map[nrow][ncol] == 4 || map[nrow][ncol] == 7)) return 1;
		if (col - ncol == 1 && (map[nrow][ncol] == 2 || map[nrow][ncol] == 6 || map[nrow][ncol] == 7)) return 1;
	}
	return 0;
}

void bfs(int x, int y) {
	queue<Node> q;
	q.push({ x, y });
	used[x][y] = 1;
	ans += 1;
	int de = 1;

	while(!q.empty()){
		Node now = q.front();
		q.pop();
		if (used[now.row][now.col] == L) return;
		for (int i = 0; i < 4; i++) {
			int nrow = now.row + dr[i];
			int ncol = now.col + dc[i];
			if (nrow < 0 && ncol < 0 && nrow >= N && ncol >= M) continue;
			if (map[nrow][ncol] == 0) continue;
			if (used[nrow][ncol] != 0) continue;

			if(check(now.row, now.col, nrow, ncol)) continue;

			used[nrow][ncol] = used[now.row][now.col] + 1;
			if (used[nrow][ncol] <= L) {
				ans++;
			}
			q.push({ nrow, ncol });
		}

	}

}

void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = 0;
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
		ans = 0;
		init();
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		bfs(R, C);

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}