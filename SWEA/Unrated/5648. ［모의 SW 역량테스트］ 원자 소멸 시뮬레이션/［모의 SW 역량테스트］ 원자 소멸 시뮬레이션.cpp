#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
	int x, y, D, E;
};
int N, ans;
int map[4001][4001] = { 0, };
int min_x, min_y, max_x, max_y;
vector<Node> virus;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int check(int row, int col) {
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < virus.size(); i++) {
		if (row == virus[i].x && col == virus[i].y) v.push_back(i);
	}

	for (int i = 0; i < v.size(); i++) {
		sum += virus[v[i]].E;
		virus[v[i]].E = 0;
	}

	return sum;
}

void simul() {
	for (int i = 0; i < virus.size(); i++) {
		if (virus[i].E == 0) continue;
		int nrow = virus[i].x + dr[virus[i].D];
		int ncol = virus[i].y + dc[virus[i].D];
		if (nrow<min_x || ncol<min_y || nrow>max_x || ncol>max_y) {
			virus[i].E = 0;
			continue;
		}
		virus[i].x = nrow; virus[i].y = ncol;
		map[nrow][ncol] += 1;
	}

	for (int i = 0; i < virus.size(); i++) {
		if (map[virus[i].x][virus[i].y] > 1) ans += check(virus[i].x, virus[i].y);
		map[virus[i].x][virus[i].y] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		virus.clear();
		min_x = 4000, min_y = 4000, max_x = 0, max_y = 0;
		for (int i = 0; i < N; i++) {
			int x, y, d, e; cin >> x >> y >> d >> e;
			if (d > 1) d -= 2;
			else if (d == 0) d = 3;
			else d += 1;
			virus.push_back({ (x+1000)*2, (y+1000)*2, d, e });
			min_x = min(min_x, (x + 1000) * 2);
			min_y = min(min_y, (y + 1000) * 2);
			max_x = max(max_x, (x + 1000) * 2);
			max_y = max(max_y, (y + 1000) * 2);
		}
		ans = 0;
		while (1) {
			int flag = 0;
			simul();
			for (int i = 0; i < virus.size(); i++) {
				if (virus[i].E == 0) flag++;
			}
			if (flag == virus.size()) break;
		}

		cout << "#" << t << " " << ans << "\n";

	}
	return 0;
}