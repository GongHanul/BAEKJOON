#include <iostream>
using namespace std;
int map[10][10] = { 0, };
int visited[10][10] = { 0, };
int ans = 213456789, apple = 0;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

void dfs(int row, int col) {
	if (apple == 3) {
		if (ans > visited[row][col] - 1) {
			ans = visited[row][col] - 1;
		}
		return;
	}
	if (ans <= visited[row][col]) return;
	
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i], nc = col + dc[i];
		if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
		if (map[nr][nc] == -1 || visited[nr][nc] != 0) continue;
		visited[nr][nc] = visited[row][col] + 1;
		if (map[nr][nc] == 1) apple += 1;
		dfs(nr, nc);
		visited[nr][nc] = 0;
		if (map[nr][nc] == 1) apple -= 1;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	int r, c; cin >> r >> c;
	visited[r][c] = 1;
	dfs(r, c);
	if (ans == 213456789) ans = -1;
	cout << ans;

	return 0;
}