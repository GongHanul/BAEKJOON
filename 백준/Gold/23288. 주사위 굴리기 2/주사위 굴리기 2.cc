#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int x, y;
};

int N, M, K, direction, st, en;
int map[22][22];
int dice[4][3] = {
	{0, 2, 0},
	{4, 1, 3},
	{0, 5, 0},
	{0, 6, 0},
};
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

int bfs() {
	int visited[22][22] = { 0, };
	queue<Node> q;
	q.push({ st, en });
	visited[st][en] = 1;
	int num = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.x + dr[i];
			int nc = now.y + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (map[nr][nc] != map[st][en]) continue;
			if (visited[nr][nc] != 0) continue;
			visited[nr][nc] = 1;
			num += 1;
			q.push({ nr, nc });
		}
	}
	return num;
}

void roll(int dir) {
	// 0: right, 1: down, 2: left, 3: up
	int temp = dice[3][1];
	if (dir == 0) {
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;
	}
	else if (dir == 1) {
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
	}
	else if (dir == 2) {
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;
	}
	else {
		dice[3][1] = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = temp;
	}
}

void dir_check() {
	int nr = st + dr[direction];
	int nc = en + dc[direction];
	if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
		st = nr, en = nc;
		return;
	}
	direction = (direction + 2) % 4;
	if (nr < 0 || nr >= N) st += dr[direction];
	if (nc < 0 || nc >= M) en += dc[direction];
	return;
}

void dice_dir() {
	if (dice[3][1] > map[st][en]) direction += 1;
	else if (dice[3][1] < map[st][en]) direction -= 1;
	if (direction < 0) direction += 4;
	direction %= 4;
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	st = 0, en = 0;
	direction = 0;
	int ans = 0;
	while (K--) {
		dir_check();
		roll(direction);
		
		ans += bfs() * map[st][en];
		dice_dir();
	}

	cout << ans;

	return 0;
}