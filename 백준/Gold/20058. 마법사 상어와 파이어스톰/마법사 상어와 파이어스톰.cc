#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N, Q, n;
int map[70][70] = { 0, };
int copy_map[70][70] = { 0, };
int visited[70][70] = { 0, };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

struct Node {
    int x, y;
};

void check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num = 0;
            if (copy_map[i - 1][j] > 0) num += 1;
            if (copy_map[i + 1][j] > 0) num += 1;
            if (copy_map[i][j - 1] > 0) num += 1;
            if (copy_map[i][j + 1] > 0) num += 1;
            if (num < 3) map[i][j] -= 1;
        }
    }
}

void rotate_map(int row, int col, int range) {
    int num2 = 1;
    for (int i = row; i < row + range; i++) {
        int num1 = row;
        for (int j = col; j < col + range; j++) {
            copy_map[num1][col + range - num2] = map[i][j];
            num1++;
        }
        num2++;
    }
}

void range_map(int od) {
    int range = pow(2, od);
    for (int i = 1; i <= n; i += range) {
        for (int j = 1; j <= n; j += range) {
            rotate_map(i, j, range);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = copy_map[i][j];
        }
    }
}

int bfs(int row, int col) {
    int cnt = 1;
    queue<Node> q;
    q.push({ row, col });
    visited[row][col] = 1;
    while (!q.empty()) {
        Node now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nrow = now.x + dr[i];
            int ncol = now.y + dc[i];
            if (nrow < 1 || ncol < 1 || nrow > n || ncol > n) continue;
            if (map[nrow][ncol] <= 0) continue;
            if (visited[nrow][ncol] != 0) continue;
            visited[nrow][ncol] = 1;
            cnt++;
            q.push({ nrow, ncol });
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    n = pow(2, N);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    for (int k = 0; k < Q; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                copy_map[i][j] = map[i][j];
            }
        }
        int order; cin >> order;
        if (order != 0) range_map(order);
        check();
    }

    int ans = 0, maxx = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] > 0) {
                ans += map[i][j];
                if (visited[i][j] == 0) {
                    maxx = max(maxx, bfs(i, j));
                }
            }
        }
    }
    if (maxx < 2) maxx = 0;

    cout << ans << "\n" << maxx << "\n";

    return 0;
}