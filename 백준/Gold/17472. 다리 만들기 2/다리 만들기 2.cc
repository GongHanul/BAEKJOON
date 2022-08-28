#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int MAP[10][10];
int visited[10][10];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int parent[10];
int cnt = 0;

struct Node {
	int row, col;
};

struct Edge {
	int from, to, cost;
};
vector<Edge> v;

bool cmp(Edge A, Edge B) {
	if (A.cost < B.cost) return true;
	if (A.cost > B.cost) return false;
	return false;
}

void makebridge(int row, int col) {
	for (int i = 0; i < 4; i++) {
		int dist = 1;
		while (true) {
			int nr = row + dr[i] * dist;
			int nc = col + dc[i] * dist;

			if (nr < 0 || nc < 0 || nr >= N || nc >= M) break;
			if (MAP[nr][nc] == MAP[row][col]) break;
			if (MAP[nr][nc] > 0) {
				if (dist <= 2) {
					break;
				}
				v.push_back({ MAP[row][col], MAP[nr][nc], dist - 1 });
				break;
			}
			dist++;
		}
	}
}

void bfs(int row, int col, int num) {
	queue<Node> q;
	q.push({ row, col });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.row + dr[i];
			int nc = now.col + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (MAP[nr][nc] != 1) continue;
			if (visited[nr][nc] != 0) continue;
			visited[nr][nc] = 1;
			MAP[nr][nc] = num;
			q.push({ nr, nc });
		}
	}
}

int Find(int now) {
	if (now == parent[now]) {
		return now;
	}
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
}

int kruskal() {
	int sum = 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		Edge now = v[i];
		if (Find(now.from) == Find(now.to)) continue;
		Union(now.from, now.to);
		cnt++;
		sum += now.cost;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	// MAP 입력받기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			visited[i][j] = 0;
		}
	}

	// 1, 섬 번호 부여
	int num = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] != 0 && visited[i][j] == 0) {
				MAP[i][j] = num;
				visited[i][j] = 1;
				bfs(i, j, num);
				num++;
			}
		}
	}

	// 2. 다리 놓기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] > 0) {
				makebridge(i, j);
			}
		}
	}

	for (int i = 0; i <= num; i++) {
		parent[i] = i;
	}

	if (v.empty()) {
		cout << -1;
	}
	else {
		int ans = kruskal();
		if (cnt == num - 2) {
			cout << ans;
		}
		else {
			cout << -1;
		}
	}
	
	return 0;
}