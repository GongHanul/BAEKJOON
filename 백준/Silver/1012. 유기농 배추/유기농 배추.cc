#include <iostream>
using namespace std;

int arr[50][50] = { 0, };
int used[50][50] = { 0, };
int M, N, K;
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = 0;
            used[i][j] = 0;
        }
    }
}

void dfs(int row, int col) {
    used[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int n_row = row + dr[i];
        int n_col = col + dc[i];
        if (n_row < 0 || n_row >= N || n_col < 0 || n_col >= M) continue;
        if (arr[n_row][n_col] == 1 && used[n_row][n_col] == 0) {
            dfs(n_row, n_col);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int num;
    cin >> num;
    while (num--) {
        reset();
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int bug = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 1 && used[i][j] == 0) {
                    dfs(i, j);
                    bug++;
                }
            }
        }
        cout << bug << endl;
    }
    return 0;
}