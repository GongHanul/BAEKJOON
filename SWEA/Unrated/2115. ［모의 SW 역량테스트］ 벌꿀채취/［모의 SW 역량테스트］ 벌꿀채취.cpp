#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
	int x, y;
};
int ans, N, M, C;
int map[10][10];
int map_dp[10][10];
vector<Node> v;
int maxx, Maxx;

void calc() {
	Maxx = map_dp[v[0].x][v[0].y] + map_dp[v[M].x][v[M].y];
	ans = max(ans, Maxx);
	return;
}

void dfs() {
	if (v.size() == M * 2) {
		calc();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			int flag = 0;
			if (j + M > N) continue;
			if (v.size() != 0) {
				if (v[0].x == i) {
					for (int k = 0; k < M; k++) {
						if (v[k].y >= j) flag = 1;
					}
				}
			}
			if (flag == 1) {
				continue;
			}
			for (int k = 0; k < M; k++) {
				v.push_back({ i, j + k });
			}
			dfs();
			for (int k = 0; k < M; k++) {
				v.pop_back();
			}
		}
	}
}
vector<int> choose;
void dfs_val(int i, int j, int m, int count) {
	int len = choose.size();
	if (len == count) {
		int s1 = 0;
		int s2 = 0;
		for (int a = 0; a < len; a++) {
			s1 += map[i][choose[a]];
			s2 += map[i][choose[a]] * map[i][choose[a]];
		}
		if (s1 <= C) {
			if (maxx < s2) {
				maxx = s2;
			}
		}
		return;
	}

	for (int a = j; a < m; a++) {
		choose.push_back(a);
		dfs_val(i, a + 1, m, count);
		choose.pop_back();
	}
}

void dp() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			int s = 0;
			int s_v = 0;
			for (int k = 0; k < M; k++) {
				s += map[i][j + k];
				s_v += map[i][j + k] * map[i][j + k];
			}
			if (s > C) {
				maxx=0;
				for (int k = 1; k < M; k++) {
					dfs_val(i, j, j + M, k);
				}
				map_dp[i][j] = maxx;
			}
			else {
				map_dp[i][j] = s_v;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 0;
		maxx = 0;
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		dp();
		dfs();

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}