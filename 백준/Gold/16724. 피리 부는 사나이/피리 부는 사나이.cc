#include <iostream>
using namespace std;

int N, M, ans;
int map[1001][1001];
int visited[1001][1001];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };


void run(int row, int col) {

    int nr = row + dr[map[row][col]];
    int nc = col + dc[map[row][col]];

    if (visited[nr][nc] == visited[row][col]) {
        ans += 1;
        visited[row][col] = -1;
        return;
    }
    if (visited[nr][nc] > 0) {
        return;
    }

    visited[nr][nc] = visited[row][col];

    run(nr, nc);
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch; cin >> ch;
            if (ch == 'U') map[i][j] = 0;
            else if (ch == 'D') map[i][j] = 1;
            else if (ch == 'L') map[i][j] = 2;
            else map[i][j] = 3;
        }
    }
    ans = 0;
    int cnt = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                visited[i][j] = cnt;
                run(i, j);
                cnt += 1;
            }
        }
    }
    cout << ans;
    return 0;
}
