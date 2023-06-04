#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int x, y, val;
};

int N, ans;
int map[22][22];
int shark = 2;
int st, en;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };
bool eat;

void bfs(int row, int col, int visited[][22], int cnt) {
	int temp = 213456789;
	queue<Node> q;
	q.push({ row, col, cnt });
	visited[row][col] = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (map[now.x][now.y] != 0 && map[now.x][now.y] < shark && temp == now.val) {
			if (st > now.x || (st == now.x && en > now.y)) {
				st = now.x, en = now.y;
				continue;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nr = now.x + dr[i];
			int nc = now.y + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (visited[nr][nc] != 0) continue;
			if (map[nr][nc] > shark) continue;
			if (map[nr][nc] != 0 && map[nr][nc] < shark && !eat) {
				eat = true;
				st = nr, en = nc;
				temp = min(temp, now.val + 1);
			}
			visited[nr][nc] = visited[now.x][now.y] + 1;
			q.push({ nr, nc, now.val + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				st = i, en = j;
			}
		}
	}
	eat = false;
	ans = 0;
	int cnt = 0;
	while (1) {
		int visited[22][22] = { 0, };
		bfs(st, en, visited, 0);
		if (eat) {
			eat = false;
			map[st][en] = 0;
			ans += visited[st][en] - 1;
			cnt += 1;
			if (cnt == shark) {
				cnt = 0;
				shark += 1;
			}
		}
		else break;
	}

	cout << ans;

	return 0;
}