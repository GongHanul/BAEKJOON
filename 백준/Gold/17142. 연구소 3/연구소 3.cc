#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int x, y;
};

int N, M, ans, mtime, num, zero_num;
int map[55][55], copy_map[55][55];
vector<Node> virus;
int check[11];
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void run() {
	queue<Node> q;
	int visited[55][55] = { 0, };
	for (int i = 0; i < num; i++) {
		if (check[i] == 1) {
			q.push({ virus[i].x, virus[i].y });
			copy_map[virus[i].x][virus[i].y] = 1;
			visited[virus[i].x][virus[i].y] = 1;
		}
	}

	while (!q.empty()) {
		int zero_cnt = zero_num;
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.x + dr[i];
			int nc = now.y + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (visited[nr][nc] != 0) continue;
			if (copy_map[nr][nc] == 0 || copy_map[nr][nc] == 2) {
				copy_map[nr][nc] = copy_map[now.x][now.y] + 1;
				visited[nr][nc] = 1;
				q.push({ nr, nc });
				if(copy_map[nr][nc] == 0) zero_cnt--;
				if (zero_cnt == 0) return;
			}
 		}
	}
}

int Check_map() {
	mtime = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copy_map[i][j] == 0) return 0;
			if(map[i][j] == 0) mtime = max(mtime, copy_map[i][j] - 1);
		}
	}
	return 1;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}

void simul(int idx, int cnt) {
	if (cnt == M) {
		init();
		run();
		if (Check_map()) {
			ans = min(ans, mtime);
		}
		return;
	}

	for (int i = idx; i < num; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			simul(i, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	num = 0; zero_num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zero_num++;
			if (map[i][j] == 2) {
				virus.push_back({ i, j });
				num += 1;
			}
		}
	}
	if (zero_num == 0) {
		cout << 0;
		return 0;
	}

	ans = 213456789;
	simul(0, 0);

	if (ans == 213456789) ans = -1;
	cout << ans;

	return 0;
}