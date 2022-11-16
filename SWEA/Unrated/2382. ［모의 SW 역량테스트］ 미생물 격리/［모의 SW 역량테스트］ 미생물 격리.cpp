#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
	int x, y, num, dir;
};

int N, M, K;
int dat[100][100];
vector<Node> virus;

int dr[] = { 0, -1, 1, 0, 0 };
int dc[] = { 0, 0, 0, -1, 1 };

void check(int row, int col) {
	vector<int> v;
	for (int i = 0; i < K; i++) {
		if (virus[i].x == row && virus[i].y == col) v.push_back(i);
	}
	int maxnum = -1, maxidx = -1, sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (maxnum < virus[v[i]].num) {
			maxnum = virus[v[i]].num;
			maxidx = v[i];
		}
		sum += virus[v[i]].num;
	}
	virus[maxidx].num = sum;
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != maxidx) virus[v[i]].num = 0;
	}

}

void simul() {
	for (int i = 0; i < K; i++) {
		if (virus[i].num == 0) continue;
		int nrow = virus[i].x + dr[virus[i].dir];
		int ncol = virus[i].y + dc[virus[i].dir];
		// 약품이 칠해진 부분은 num을 절반으로 나누고 방향 180도 반대로
		if (nrow == 0 || ncol == 0 || nrow == N - 1 || ncol == N - 1) {
			virus[i].num /= 2;
			if (virus[i].dir == 1) virus[i].dir = 2;
			else if (virus[i].dir == 2) virus[i].dir = 1;
			else if (virus[i].dir == 3) virus[i].dir = 4;
			else virus[i].dir = 3;
		}
		virus[i].x = nrow; virus[i].y = ncol;
		dat[virus[i].x][virus[i].y]++;
	}

	// 같은 부분에 위치할 경우 찾기
	for (int i = 0; i < K; i++) {
		if (dat[virus[i].x][virus[i].y] > 1) check(virus[i].x, virus[i].y);
		dat[virus[i].x][virus[i].y] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		virus.clear();
		for (int i = 0; i < K; i++) {
			int x, y, num, dir;
			cin >> x >> y >> num >> dir;
			virus.push_back({ x, y, num, dir });
		}

		while (M--) {
			simul();
		}
		int ans = 0;
		for (int i = 0; i < virus.size(); i++) {
			ans += virus[i].num;
		}

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}