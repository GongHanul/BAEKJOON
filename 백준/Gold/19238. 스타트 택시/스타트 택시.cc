#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int x, y, nx, ny;
	bool check;
};
struct Coord {
	int x, y;
};

int N, M, K;
int map[22][22];
int st, en, cnt;
vector<Node> passenger;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void geton(int visit[][22], int row, int col) {
	queue<Coord> q;
	visit[row][col] = 1;
	q.push({ row, col });
	while (!q.empty()) {
		Coord now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.x + dr[i];
			int nc = now.y + dc[i];
			if (nr<1 || nc<1 || nr>N || nc>N) continue;
			if (visit[nr][nc] != 0) continue;
			if (map[nr][nc] == 1) continue;
			visit[nr][nc] = visit[now.x][now.y] + 1;
			q.push({ nr, nc });
		}
	}
}

int getoff(int row, int col) {
	int visit[22][22] = { 0, };
	queue<Coord> q;
	visit[st][en] = 1;
	q.push({ st, en });
	while (!q.empty()) {
		Coord now = q.front(); q.pop();
		if (now.x == row && now.y == col) {
			st = row, en = col;
			return visit[now.x][now.y] - 1;
		}
		for (int i = 0; i < 4; i++) {
			int nr = now.x + dr[i];
			int nc = now.y + dc[i];
			if (nr<1 || nc<1 || nr>N || nc>N) continue;
			if (map[nr][nc] == 1) continue;
			if (visit[nr][nc] != 0) continue;
			visit[nr][nc] = visit[now.x][now.y] + 1;
			q.push({ nr, nc });
		}
	}
	return -1;
}

bool simul() {
	int visited[22][22] = { 0, };
	geton(visited, st, en);
	int minn = 213456789, idx = -1;
	for (int i = 0; i < passenger.size(); i++) {
		if (passenger[i].check == false) continue;
		if (minn == visited[passenger[i].x][passenger[i].y] - 1) {
			if (passenger[i].x < st || (passenger[i].x == st && passenger[i].y < en)) {
				st = passenger[i].x, en = passenger[i].y;
				idx = i;
			}
		}
		if (minn > visited[passenger[i].x][passenger[i].y] - 1) {
			minn = visited[passenger[i].x][passenger[i].y] - 1;
			st = passenger[i].x, en = passenger[i].y;
			idx = i;
		}
	}
	map[st][en] = 0;
	K -= minn;
	if (K < 0 || minn == -1) return false;

	int val = getoff(passenger[idx].nx, passenger[idx].ny);
	if (K - val < 0 || val == -1) return false;
	K += val;
	passenger[idx].check = false;
	cnt -= 1;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> st >> en;
	int x, y, nx, ny;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> nx >> ny;
		map[x][y] = 2;
		passenger.push_back({ x, y, nx, ny, true });
	}

	for (int i = 0; i < M; i++) {
		if (!simul()) {
			cout << -1;
			return 0;
		}
	}

	cout << K;

	return 0;
}