#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int row, col;
};

int N;
int map[25][25];
vector<int> student[410];
vector<Node> seat[410];
vector<Node> Score;
int st_num[410];
int check[410];
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void check_score_blank(int row, int col, int st) {
	Score.clear();
	int score = 0, blank = 0;
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		if (map[nr][nc] == 0) blank += 1;
		else {
			for (int j = 0; j < 4; j++) {
				if (student[st][j] == map[nr][nc]) score += 1;
			}
		}
	}
	Score.push_back({ score, blank });

}

void check_side(int st) {
	int sr = 20, sc = 20;
	int score = -1, blank = -1;
	bool flag = false;

	for (int i = 0; i < 4; i++) {
		int t = student[st][i];
		if (check[t] == 1) {
			for (int j = 0; j < 4; j++) {
				int nr = seat[t][0].row + dr[j];
				int nc = seat[t][0].col + dc[j];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if (map[nr][nc] != 0) continue;
				flag = true;
				check_score_blank(nr, nc, st);
				if (Score[0].row > score) {
					score = Score[0].row;
					blank = Score[0].col;
					sr = nr; sc = nc;
				}
				else if (Score[0].row == score) {
					if (Score[0].col > blank) {
						blank = Score[0].col;
						sr = nr, sc = nc;
					}
					else if (Score[0].col == blank) {
						if (sr > nr) {
							sr = nr, sc = nc;
						}
						else if (sr == nr && sc > nc) {
							sc = nc;
						}
					}
				}
			}
		}
	}

	if (!flag) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					check_score_blank(i, j, st);
					if (Score[0].col > blank) {
						blank = Score[0].col;
						sr = i, sc = j;
						if (blank == 4) {
							map[sr][sc] = st;
							seat[st].push_back({ sr, sc });
							return;
						}
					}
					else if (Score[0].col == 0) {
						if (sr > i) {
							sr = i, sc = j;
						}
						else if (sr == i && sc > j) {
							sc = j;
						}
					}
				}
			}
		}
	}
	map[sr][sc] = st;
	seat[st].push_back({ sr, sc });

	return;
}

void simul() {
	for (int i = 0; i < N * N; i++) {
		check_side(st_num[i]);
		check[st_num[i]] = 1;
	}

	return;
}

int calc() {
	int ans = 0;
	int target[5] = { 0, 1, 10, 100, 1000 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check_score_blank(i, j, map[i][j]);
			ans += target[Score[0].row];
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N * N; i++) {
		int num; cin >> num;
		st_num[i] = num;
		for (int j = 0; j < 4; j++) {
			int a; cin >> a;
			student[num].push_back(a);
		}
	}

	simul();

	cout << calc();

	return 0;
}