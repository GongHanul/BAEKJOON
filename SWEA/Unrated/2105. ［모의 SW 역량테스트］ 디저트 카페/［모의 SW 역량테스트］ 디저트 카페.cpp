#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int map[20][20];
int used[20][20];
int dat[101] = { 0, };
int st_row, st_col;
int dr[] = { 1, 1, -1, -1 };
int dc[] = { -1, 1, 1, -1 };

void dfs(int row, int col, int cnt) {
	if (row == st_row && col == st_col && used[row][col]) {
		ans = max(ans, used[row][col]);
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nrow = row + dr[cnt + i];
		int ncol = col + dc[cnt + i];
		if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) continue;
		if (used[nrow][ncol] != 0) continue;
		if (dat[map[nrow][ncol]] != 0) continue;
		if (cnt + i >= 4) continue;
		used[nrow][ncol] = used[row][col] + 1;
		dat[map[nrow][ncol]]++;
		dfs(nrow, ncol, cnt + i);
		used[nrow][ncol] = 0;
		dat[map[nrow][ncol]] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				st_row = i;
				st_col = j;
				dfs(i, j, 0);
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}