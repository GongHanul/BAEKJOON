#include <iostream>
#include <queue>
using namespace std;
int R, C, N;
char bomb[201][201];
int visited[201][201] = { 0, };

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

void simul(int now) {
	if (N % 2 == 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				visited[i][j] = 1;
			}
		}
	}
	else {
		queue<pair<int, int>> q;
		while (now < N) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (visited[i][j] == 1) q.push({ i, j });
					else visited[i][j] = 1;
				}
			}

			while (!q.empty()) {
				int row = q.front().first, col = q.front().second;
				visited[row][col] = 0;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nr = row + dr[i], nc = col + dc[i];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
					visited[nr][nc] = 0;
				}
			}

			now += 2;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> N;
	int num = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> bomb[i][j];
			if (bomb[i][j] == 'O') {
				visited[i][j] = 1;
			}
		}
	}
	int now = 1;
	simul(now);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] != 0) cout << "O";
			else cout << ".";
		}
		cout << "\n";
	}


	return 0;
}