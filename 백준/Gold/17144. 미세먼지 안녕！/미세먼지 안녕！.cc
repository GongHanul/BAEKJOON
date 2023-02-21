#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int x, y;
};
int R, C, T;
int map[51][51] = { 0, };
int copy_map[51][51] = { 0, };
vector<Node> vacuum;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };

void diffusion() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] >= 5) {
				int num = 0;
				for (int k = 0; k < 4; k++) {
					int nrow = i + dr[k];
					int ncol = j + dc[k];
					if (nrow < 0 || ncol < 0 || nrow >= R || ncol >= C) continue;
					if (map[nrow][ncol] == -1) continue;
					copy_map[nrow][ncol] += map[i][j] / 5;
					num++;
				}
				map[i][j] -= map[i][j] / 5 * num;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += copy_map[i][j];
			copy_map[i][j] = 0;
		}
	}
}

void cleaner() {
	for (int i = vacuum[0].x; i > 0; i--) {
		map[i][0] = map[i - 1][0];
	}
	for (int i = vacuum[1].x; i < R - 1; i++) {
		map[i][0] = map[i + 1][0];
	}
	map[vacuum[0].x][0] = -1, map[vacuum[1].x][0] = -1;

	for (int i = 0; i < C - 1; i++) {
		map[0][i] = map[0][i + 1];
		map[R - 1][i] = map[R - 1][i + 1];
	}

	for (int i = 0; i < vacuum[0].x; i++) {
		map[i][C - 1] = map[i + 1][C - 1];
	}
	for (int i = R - 1; i > vacuum[1].x; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}

	for (int i = C - 1; i > 1; i--) {
		map[vacuum[0].x][i] = map[vacuum[0].x][i - 1];
		map[vacuum[1].x][i] = map[vacuum[1].x][i - 1];
	}
	map[vacuum[0].x][1] = 0, map[vacuum[1].x][1] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) vacuum.push_back({ i, j });
		}
	}

	while (T--) {
		// 미세먼지 확산
		diffusion();

		// 공기청정기 작동
		cleaner();
	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}

	cout << ans;

	return 0;
}