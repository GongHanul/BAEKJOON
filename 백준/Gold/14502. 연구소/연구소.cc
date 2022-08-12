#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	int row, col;
};

int MAP[10][10];
int N, M;
vector<Node> blank;
queue<Node> virus;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int bfs() {
	int blankCnt = 0;
	int visited[10][10] = { 0, };
	queue<Node> q=virus;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_row = now.row + dr[i];
			int n_col = now.col + dc[i];
			if (MAP[n_row][n_col] != 0) continue;
			if (visited[n_row][n_col]) continue;
			visited[n_row][n_col] = 1;
			blankCnt++;
			q.push({ n_row, n_col });
		}
	}
	return blank.size() - 3 - blankCnt;
}

void SetWall(Node coord, int stat) {
	MAP[coord.row][coord.col] = stat;
}

int solution() {
	int maxVal = 0;
	for (int i = 0; i < blank.size(); i++) {
		for (int j = i + 1; j < blank.size(); j++) {
			for (int k = j + 1; k < blank.size(); k++) {
				SetWall(blank[i], 1);
				SetWall(blank[j], 1);
				SetWall(blank[k], 1);
				maxVal = max(maxVal, bfs());
				SetWall(blank[i], 0);
				SetWall(blank[j], 0);
				SetWall(blank[k], 0);
			}
		}
	}
	return maxVal;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			MAP[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) blank.push_back({ i, j });
			if (MAP[i][j] == 2) virus.push({ i, j });
		}
	}

	cout << solution();

	return 0;
}