#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
	int x, y, num, dir;
};
int N, M, K;
vector<Node> v;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int dat[100][100] = { 0, };

void check(int row, int col) {
	vector<int> coord;
	for (int i = 0; i < v.size(); i++) {
		if (row == v[i].x && col == v[i].y) {
			coord.push_back(i);
		}
	}
	int maxx = 0, max_index = 0, dir = 0, sum_num = 0;
	for (int i = 0; i < coord.size(); i++) {
		if (maxx < v[coord[i]].num) {
			maxx = v[coord[i]].num;
			max_index = coord[i];
			dir = v[coord[i]].dir;
		}
		sum_num += v[coord[i]].num;
		v[coord[i]].num = 0;
	}
	for (int i = 0; i < coord.size(); i++) {
		if (coord[i] == max_index) v[coord[i]].num = sum_num;
	}

}

void Move() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].num == 0) continue;
		int nx = v[i].x + dr[v[i].dir];
		v[i].x = nx;
		int ny = v[i].y + dc[v[i].dir];
		v[i].y = ny;
		if (nx == 0 || ny == 0 || nx == N - 1 || ny == N - 1) {
			v[i].num /= 2;
			if (v[i].dir == 1 || v[i].dir == 3) v[i].dir -= 1;
			else v[i].dir += 1;
		}
		dat[nx][ny]++;

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dat[i][j] > 1) {
				check(i, j);
				dat[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int x, y, num, dir;
			cin >> x >> y >> num >> dir;
			v.push_back({ x, y, num, dir-1 });
		}

		for (int i = 0; i < M; i++) {
			Move();
			int de = 1;
		}
		int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			ans += v[i].num;
		}
		cout << "#" << t << " " << ans << "\n";

	}
	return 0;
}