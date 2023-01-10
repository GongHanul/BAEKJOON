#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int x, y, m, s, d;
};

int N, M, K;
vector<Node> v;
vector<Node> map[55][55];

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void check() {
    vector<Node> temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j].size() == 0) continue;
            if (map[i][j].size() == 1) {
                temp.push_back({ map[i][j][0] });
                continue;
            }
            int m = 0, s = 0;
            bool dir_check = true;
            int d = map[i][j][0].d % 2;
            for (int k = 0; k < map[i][j].size(); k++) {
                m += map[i][j][k].m;
                s += map[i][j][k].s;
                if (d != map[i][j][k].d % 2) dir_check = false;
            }
            m /= 5;
            s /= map[i][j].size();
            if (m == 0) continue;
            if (dir_check == true) {
                for (int k = 0; k < 4; k++) {
                    temp.push_back({ i, j, m, s, k * 2 });
                }
            }
            else {
                for (int k = 0; k < 4; k++) {
                    temp.push_back({ i, j, m, s, k * 2 + 1 });
                }
            }
        }
    }

    v = temp;
}

int direction(int val) {
    if (val < 0) val += N;
    if (val >= N) val -= N;
    return val;
}

void run() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j].clear();
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i].m == 0) continue;
        int s = v[i].s % N;
        v[i].x = direction(v[i].x + dr[v[i].d] * s);
        v[i].y = direction(v[i].y + dc[v[i].d] * s);
        map[v[i].x][v[i].y].push_back({ v[i].x, v[i].y, v[i].m, v[i].s, v[i].d });
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
        v.push_back({ r - 1, c - 1, m, s, d });
    }

    while (K--) {
        run();
        check();
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += v[i].m;
    }

    cout << ans;

    return 0;
}