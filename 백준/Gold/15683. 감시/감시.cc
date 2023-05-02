#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int row, col, val;
};

int N, M, ans;
int map[10][10] = { 0, };
//int c_map[10][10] = { 0, };
vector<Node> cctv;
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int check[10] = { 0, };

int zero_num() {
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) num++;
        }
    }
    return num;
}

void dfs(int row, int col, int dir) {
    int nr = row + dr[dir];
    int nc = col + dc[dir];
    if (map[nr][nc] == 6) return;
    if (nr < 0 || nc < 0 || nr >= N || nc >= M) return;
    if (map[nr][nc] == 0) map[nr][nc] = -1;
    dfs(nr, nc, dir);
}

void solution(int cnt) {
    if (cnt == cctv.size()) {
        ans = min(ans, zero_num());
        return;
    }
    int c_map[10][10] = { 0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            c_map[i][j] = map[i][j];
        }
    }

    int row = cctv[cnt].row;
    int col = cctv[cnt].col;
    int val = cctv[cnt].val;

    for (int i = 0; i < 4; i++) {
        check[cnt] = i;
        if (val == 0) {
            dfs(row, col, val + i);
        }
        else if (val == 1) {
            dfs(row, col, ((val - 1) + i) % 4);
            dfs(row, col, ((val + 1) + i) % 4);
        }
        else if (val == 2) {
            dfs(row, col, ((val - 2) + i) % 4);
            dfs(row, col, ((val + 1) + i) % 4);
        }
        else if (val == 3) {
            dfs(row, col, ((val - 3) + i) % 4);
            dfs(row, col, ((val - 1) + i) % 4);
            dfs(row, col, (val + i) % 4);
        }
        else {
            if (check[cnt] == 0) {
                check[cnt] = 1;
                dfs(row, col, 0);
                dfs(row, col, 1);
                dfs(row, col, 2);
                dfs(row, col, 3);
            }
        }
        solution(cnt + 1);
        if (check[cnt] != 0) check[cnt] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = c_map[i][j];
            }
        }
        int de = 1;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] > 0 && map[i][j] < 6) {
                cctv.push_back({ i, j, map[i][j]-1 });
            }
        }
    }
    ans = 213456789;
    solution(0);

    cout << ans;

    return 0;
}
