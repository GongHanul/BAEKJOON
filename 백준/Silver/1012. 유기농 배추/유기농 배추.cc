#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int map[55][55];
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void init() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}

void dfs(int row, int col) {
	for (int i = 0; i < 4; i++) {
		int nrow = row + dr[i];
		int ncol = col + dc[i];
		if (nrow < 0 || ncol < 0 || nrow >= M || ncol >= N) continue;
		if (map[nrow][ncol] != 1) continue;
		map[nrow][ncol] = 0;
		dfs(nrow, ncol);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int ans = 0;
		init();
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int r, c; cin >> r >> c;
			map[r][c] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					ans += 1;
				}
			}
		}

		cout << ans << "\n";
	}
	return 0;
}