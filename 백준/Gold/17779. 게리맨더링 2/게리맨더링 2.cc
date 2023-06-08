#include <iostream>

using namespace std;

int N, ans;
int map[25][25];

int sect(int row, int col, int d1, int d2) {
	int visited[25][25] = { 0, };
	int maxx = -1, minn = 213456789;
	// sect 1
	int sum = 0, idx = col;
	for (int i = 1; i < row + d1; i++) {
		for (int j = 1; j <= idx; j++) {
			sum += map[i][j];
			visited[i][j] = 1;
		}
		if(i+1 >= row) idx -= 1;
	}
	maxx = max(maxx, sum), minn = min(minn, sum);

	// sect 2
	sum = 0, idx = col + 1;
	for (int i = 1; i <= row + d2; i++) {
		for (int j = idx; j <= N; j++) {
			sum += map[i][j];
			visited[i][j] = 2;
		}
		if (i+1 > row) idx += 1;
	}
	maxx = max(maxx, sum), minn = min(minn, sum);

	// sect 3
	sum = 0, idx = col - d1;
	for (int i = row + d1; i <= N; i++) {
		for (int j = 1; j < idx; j++) {
			sum += map[i][j];
			visited[i][j] = 3;
		}
		if (i < row + d1 + d2) idx += 1;
	}
	maxx = max(maxx, sum), minn = min(minn, sum);

	// sect 4
	sum = 0, idx = col + d2;
	for (int i = row + d2 + 1; i <= N; i++) {
		for (int j = idx; j <= N; j++) {
			sum += map[i][j];
			visited[i][j] = 4;
		}
		if (i <= row + d1 + d2) idx -= 1;
	}
	maxx = max(maxx, sum), minn = min(minn, sum);

	// sect 5
	sum = 0;
	int idx1 = col, idx2 = col + 1;
	for (int i = row; i <= row + d1 + d2; i++) {
		for (int j = idx1; j < idx2; j++) {
			sum += map[i][j];
			visited[i][j] = 5;
		}
		if (i < row + d1) idx1 -= 1;
		if (i < row + d2) idx2 += 1;
		if (i >= row + d1) idx1 += 1;
		if (i >= row + d2) idx2 -= 1;
	}
	maxx = max(maxx, sum), minn = min(minn, sum);

	return maxx - minn;
}

void simul(int row, int col) {
	int visited[25][25] = {0, };
	for (int d1 = 1; d1 < col; d1++) {
		for (int d2 = 1; d2 <= N - col; d2++) {
			if (row + d1 + d2 > N) continue;
			visited[row][col] = 1;
			visited[row + d1][col - d1] = 1;
			visited[row + d2][col + d2] = 1;
			visited[row + d1 + d2][col - d1 + d2] = 1;
			ans = min(ans, sect(row, col, d1, d2));

			visited[row][col] = 0;
			visited[row + d1][col - d1] = 0;
			visited[row + d2][col + d2] = 0;
			visited[row + d1 + d2][col - d1 + d2] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	ans = 213456789;
	// 1행과 1열은 d1, d2가 1이므로 계산x
	for (int i = 1; i < N-1; i++) {
		for (int j = 2; j < N; j++) {
			simul(i, j);
		}
	}
	
	cout << ans;

	return 0;
}