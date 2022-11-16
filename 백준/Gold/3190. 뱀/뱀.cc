#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int x, y, time, dir;
};
struct Coord {
	int x, y;
};

int N, K, L, ans;
int map[110][110] = { 0, };
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
char dat[10001];
queue<Coord> q;

void solution() {
	Node now = { 1, 1, 0, 0 };
	q.push({ 1, 1 });
	map[1][1] = 2;
	while (1) {
		now.time++;
		// 앞으로 가야할 부분이
		int nrow = now.x + dr[now.dir];
		int ncol = now.y + dc[now.dir];
		// map 밖으로 나가는 경우 -> 끝
		if (nrow < 1 || ncol < 1 || nrow > N || ncol > N) {
			ans = now.time;
			return;
		}
		// 몸을 만나는 경우 -> 끝
		if (map[nrow][ncol] == 2) {
			ans = now.time;
			return;
		}
		// 사과가 없는 경우
		if (map[nrow][ncol] == 0) {
			map[nrow][ncol] = 2;
			map[q.front().x][q.front().y] = 0;
			q.pop();
		}
		// 사과가 있는 경우 -> 몸 늘리고 사과 없애기
		else {
			map[nrow][ncol] = 2;
		}
		q.push({ nrow, ncol });
		if (dat[now.time] == 'D') {
			now.dir++;
			if (now.dir == 4) now.dir -= 4;
		}
		else if (dat[now.time] == 'L') {
			now.dir--;
			if (now.dir < 0) now.dir += 4;
		}
		now = { nrow, ncol, now.time, now.dir };
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y; cin >> x >> y;
		map[x][y] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x; char c; cin >> x >> c;
		dat[x] = c;
	}
	ans = 0;
	solution();
	cout << ans << "\n";

	return 0;
}