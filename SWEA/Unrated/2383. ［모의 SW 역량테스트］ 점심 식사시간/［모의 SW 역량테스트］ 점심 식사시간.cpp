#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point {
	int x, y;
};
int N, ans;
int map[10][10];
vector<Point> h;
vector<Point> stair;
vector<int> step;

int simulation(int s) {

	vector<int> vt;
	for (int i = 0; i < h.size(); i++) {
		if (step[i] == s) {
			vt.push_back(abs(h[i].x - stair[s].x) + abs(h[i].y - stair[s].y));
		}
	}

	if (vt.size() == 0) {
		return -1;
	}

	int i = 0;
	int t = map[stair[s].x][stair[s].y];
	int s_cnt = 0;
	int st[3] = { 0, };
	for (i = 1;; i++) {
		for (int i = 0; i < 3; i++) {
			st[i]--;
		}
		if (s_cnt) {
			for (int i = 0; i < 3; i++) {
				if (st[i] <= 0) {
					st[i] = t;
					s_cnt--;
					if (s_cnt == 0) break;
				}
			}
		}
		for (int i = 0; i < vt.size(); i++) {
			vt[i]--;
			if (vt[i] == 0) {
				s_cnt++;
			}
		}

		bool check1 = true;
		bool check2 = true;
		for (int i = 0; i < vt.size(); i++) {
			if (vt[i] > 0) {
				check1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (st[i] > 0) {
				check2 = false;
				break;
			}
		}
		if (check1 && check2 && !s_cnt) break;
	}
	return i;
}

void dfs(int k) {
	if (k == h.size()) {
		int s1 = simulation(0);
		int s2 = simulation(1);

		int maxx = s1 >= s2 ? s1 : s2;
		ans = ans >= maxx ? maxx : ans;
		return;
	}

	for (int i = 0; i < 2; i++) {
		step.push_back(i);
		dfs(k + 1);
		step.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		h.clear();
		stair.clear();
		step.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					h.push_back({ i, j });
				}
				if (map[i][j] > 1) {
					stair.push_back({ i, j });
				}
			}
		}
		ans = 987654321;
		dfs(0);		

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}
