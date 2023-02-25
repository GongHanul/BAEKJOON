#include <iostream>
#include <vector>
using namespace std;

int N, M, sx, sy, K;
int map[25][25] = { 0, };
vector<int> k_order;
int dice[4][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };

void turn(int order) {
	int temp = -1;
	if (order == 0) {
		temp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = temp;
	}
	else if (order == 1) {
		temp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = temp;
	}
	else if (order == 2) {
		temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;
	}
	else {
		temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
	}
}

void move(int order) {
	int nrow = sx + dr[order];
	int ncol = sy + dc[order];
	if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= M) return;
	sx += dr[order];
	sy += dc[order];
	turn(order);
	if (map[nrow][ncol] != 0) {
		dice[3][1] = map[nrow][ncol];
		map[nrow][ncol] = 0;
	}
	else {
		map[nrow][ncol] = dice[3][1];
	}
	cout << dice[1][1] << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> sx >> sy >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int order ; cin>>order;
		k_order.push_back(order);
	}

	for (int i = 0; i < K; i++) {
		move(k_order[i] - 1);
	}

	return 0;
}