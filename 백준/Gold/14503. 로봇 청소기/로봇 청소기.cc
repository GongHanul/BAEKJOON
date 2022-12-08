#include <iostream>

using namespace std;

int N, M, r, c, d, ans;
int map[55][55];
int dr[] = { -1, 0, 1 ,0 };
int dc[] = { 0, 1, 0, -1 };

void rotate() {
	if (d == 0) d = 3;
	else d -= 1;
}

int back_move() {
	int dir = (d + 2) % 4;
	int nrow = r + dr[dir];
	int ncol = c + dc[dir];
	if (map[nrow][ncol] == 2) {
		r = nrow; c = ncol;
		return 1;
	}
	else if (map[nrow][ncol] == 1) {
		return 0;
	}
	//while (1) {
	//	int nrow = r + dr[dir];
	//	int ncol = c + dc[dir];
	//	if (map[nrow][ncol] == 2) {
	//		r = nrow; c = ncol;
	//		rotate();
	//		continue;
	//	}
	//	else if (map[nrow][ncol] == 0) {
	//		rotate();
	//		return 1;
	//	}
	//	else if (map[nrow][ncol] == 1) {
	//		return 0;
	//	}
	//}

}

void simulation() {
	int cnt = 0;
	while (1) {
		// 네 방향이 모두 막혀있을 때
		if (cnt == 4) {
			// 후진
			if(!back_move()) break;
			else {
				//ans++;
				cnt = 0;
			}
		}
		// 왼쪽으로 회전
		rotate();
		int nrow = r + dr[d];
		int ncol = c + dc[d];
		if (map[nrow][ncol] == 0) {
			map[nrow][ncol] = 2;
			r = nrow; c = ncol;
			cnt = 0;
			ans++;
			continue;
		}
		else {
			cnt++;
		}
		
	}
}

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	// 청소한 구역은 2
	map[r][c] = 2;
	ans = 1;

	simulation();

	cout << ans << "\n";

	return 0;
}