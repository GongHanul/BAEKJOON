#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int map[8][8];
int visited[8][8];
int blankCnt = 0;
struct Node {
	int row, col;
};
vector<Node> wall;
vector<Node> virus;
vector<Node> blank;

void setWall(Node now, int check) {
		map[now.row][now.col] = check;
}

void dfs(Node now) {
	int dr[] = { 0, 0, 1, -1 };
	int dc[] = { 1, -1, 0, 0 };
	for (int i = 0; i < 4; i++) {
		int nr = now.row + dr[i];
		int nc = now.col + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
		if (map[nr][nc] != 0) continue;
		if (visited[nr][nc] != 0) continue;
		visited[nr][nc] = 1;
		blankCnt++;
		dfs({ nr, nc });
	}
}

int solution() {
	int maxval = 0;
	for (int i = 0; i < blank.size(); i++) {
		for (int j = i + 1; j < blank.size(); j++) {
			for (int k = j + 1; k < blank.size(); k++) {
				setWall(blank[i], 1);
				setWall(blank[j], 1);
				setWall(blank[k], 1);
				
				for (int row = 0; row < 8; row++)
				{
					for (int col = 0; col < 8; col++)
					{
						visited[row][col] = 0;
					}
				}
				blankCnt = 0;
				for (int i = 0; i < virus.size(); i++)
				{
					dfs(virus[i]);
				}
				maxval = max(maxval, (int)blank.size() - 3 - blankCnt);

				setWall(blank[i], 0);
				setWall(blank[j], 0);
				setWall(blank[k], 0);

			}
		}
	}
	return maxval;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i, j });
			}
			else if (map[i][j] == 0) {
				blank.push_back({ i, j });
			}
		}
	}

	cout << solution();

	return 0;
}