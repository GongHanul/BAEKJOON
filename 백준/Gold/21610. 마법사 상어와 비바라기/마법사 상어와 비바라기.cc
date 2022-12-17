#include <iostream>
#include <vector>
struct Node {
	int dir, dis;
};
struct Coord {
	int x, y;
};

using namespace std;

int N, M;
int map[55][55];
int used[55][55];
int dr[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dr_diag[] = { -1, 1, -1, 1 };
int dc_diag[] = { -1, -1, 1, 1 };
vector<Node> comm;
vector<Coord> v;

void cloud_move(int dir, int dis) {
	vector<Coord> p;
	for (int i = 0; i < v.size(); i++) {
		used[v[i].x][v[i].y] = 0;
		int nrow = v[i].x + (dr[dir] * dis) % N;
		int ncol = v[i].y + (dc[dir] * dis) % N;
		// nrow와 ncol이 0보다 작을 때와 N보다 클 때
		if (nrow < 0) nrow += N;
		else if (nrow >= N) nrow -= N;
		if (ncol < 0) ncol += N;
		else if (ncol >= N) ncol -= N;

		map[nrow][ncol] += 1;
		p.push_back({ nrow, ncol });
	}
	// 각 좌표의 대각선 방향으로 0보다 큰 횟수만큼 물의 양 증가
	for (int i = 0; i < p.size(); i++) {
		int cnt = 0;
		used[p[i].x][p[i].y] = 1;
		for (int j = 0; j < 4; j++) {
			int nrow = p[i].x + dr_diag[j];
			int ncol = p[i].y + dc_diag[j];
			// nrow와 ncol이 0보다 작을 때와 N보다 클 때
			if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) continue;
			if (map[nrow][ncol] > 0) cnt++;
		}
		map[p[i].x][p[i].y] += cnt;
	}
}

void cloud_make() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (used[i][j] == 1) {
				used[i][j] = 0;
			}
			else if (used[i][j] != 1 && map[i][j] >= 2) {
				used[i][j] = 1;
				map[i][j] -= 2;
				v.push_back({ i, j });
			}
		}
	}
}

int simul() {
	// (N,1), (N,2), (N-1,1), (N-1,2)에 비구름 생성
	used[N - 1][0] = 1; used[N - 1][1] = 1; used[N - 2][0] = 1; used[N - 2][1] = 1;
	v.push_back({ N - 1, 0 }); v.push_back({ N - 1, 1 }); v.push_back({ N - 2, 0 }); v.push_back({ N - 2, 1 });

	for (int i = 0; i < M; i++) {
		// 구름 이동 및 해당 칸에 물의 양 1씩 증가
		cloud_move(comm[i].dir, comm[i].dis);
		
		// 좌표 저장된 벡터 초기화
		v.clear();

		// used가 1이 아니면서 물의 양이 2 이상인 부분에 구름 생성
		cloud_make();

	}

	// M번 이동 후 물의 양의 합
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int d, s; cin >> d >> s;
		comm.push_back({ d, s });
	}

	cout << simul();

	return 0;
}