#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, W, H, ans;
int map[15][12], cmap[15][12];
vector<int> path;

void copy_map() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cmap[i][j] = map[i][j];
		}
	}
}

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };

void boom(int row, int col) {
	int distrange = cmap[row][col];
	cmap[row][col] = 0;
	for (int i = 0; i < 4; i++) {
		for (int dist = 1; dist < distrange; dist++) {
			int nrow = row + dr[i] * dist;
			int ncol = col + dc[i] * dist;
			if (nrow < 0 || ncol < 0 || nrow >= H || ncol >= W) continue;
			if (cmap[nrow][ncol] == 0) continue;
			else boom(nrow, ncol);
		}
	}
}

void gravity() {
	for (int j = 0; j < W; j++) {
		int idx = H - 1;
		for (int i = H - 1; i >= 0; i--) {
			if (cmap[i][j] > 0) {
				int temp = cmap[i][j];
				cmap[i][j] = cmap[idx][j];
				cmap[idx][j] = temp;
				idx -= 1;
			}
		}
	}
}

int calc() {
	int sum = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (cmap[i][j] != 0) sum += 1;
		}
	}
	return sum;
}

void simul(int cnt) {
	if (cnt == N) {
		copy_map();
		for (int j = 0; j < N; j++) {
			int col = path[j];
			for (int i = 0; i < H; i++) {
				if (cmap[i][col] != 0) {
					boom(i, col);
					break;
				}
			}
			gravity();
		}
		ans = min(ans, calc());
		return;
	}
	for (int i = 0; i < W; i++) {
		path.push_back(i);
		simul(cnt + 1);
		path.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		ans = 987654321;
		simul(0);
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}