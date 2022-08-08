#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MAX 101
using namespace std;

int arr[MAX][MAX];
int used[MAX][MAX];
int dist[MAX][MAX];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int N, M;

struct Node {
	int row, col;
};

void bfs(int row, int col) {
	queue<Node> q;
	q.push({ row, col });
	used[row][col] = 1;

	while (!q.empty()) {
		int x = q.front().row;
		int y = q.front().col;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_new = x + dr[i];
			int y_new = y + dc[i];
			if (x_new < 0 || x_new >= N || y_new < 0 || y_new >= M) continue;
			if (arr[x_new][y_new] == 1 && used[x_new][y_new] == 0) {
				used[x_new][y_new] = 1;
				dist[x_new][y_new] = dist[x][y] + 1;
				q.push({ x_new, y_new });

			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		cin >> temp;
		for (int y = 0; y < M; y++) {
			arr[x][y] = temp[y]-'0';
		}
	}

	dist[0][0] = 1;

	bfs(0, 0);

	cout << dist[N - 1][M - 1];

	return 0;
}