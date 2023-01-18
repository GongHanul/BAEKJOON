#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int map[500][500] = { 0, };
int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };
int dr_move[4][10] = { {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {1, 1, 0, 0, 0, 0, -1, -1, 2, 1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, -2, -1} };
int dc_move[4][10] = { {-1, -1, 0, 0, 0, 0, 1, 1, -2, -1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {1, 1, 0, 0, 0, 0, -1, -1, 2, 1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0} };
int order[10] = { 10, 10, 7, 7, 2, 2, 1, 1, 5 };

void move(int row, int col, int dir) {
    int num = 0;
    if (map[row][col] == 0) return;
    else if (map[row][col] < 10) {
        int nrow = row + dr_move[dir][9];
        int ncol = col + dc_move[dir][9];
        if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) ans += map[row][col];
        else map[nrow][ncol] += map[row][col];
        map[row][col] = 0;
    }
    else {
        for (int i = 0; i < 10; i++) {
            int nrow = row + dr_move[dir][i];
            int ncol = col + dc_move[dir][i];
            if (i == 9) {
                if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) ans += map[row][col] - num;
                else map[nrow][ncol] += map[row][col] - num;
                map[row][col] = 0;
            }
            else {
                num += (map[row][col] * order[i]) / 100;
                if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) ans += (map[row][col] * order[i]) / 100;
                else map[nrow][ncol] += (map[row][col] * order[i]) / 100;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    int row = N / 2; int col = N / 2;
    int step = 1, dir = 0;
    ans = 0;
    while (col>=0) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < step; j++) {
                // 좌표 이동
                row += dr[dir % 4];
                col += dc[dir % 4];
                if (col < 0) break;
                // 모래 이동
                move(row, col, dir % 4);
            }
            if (col < 0) break;
            dir += 1;
        }
        step += 1;
    }
    cout << ans;

    return 0;
}