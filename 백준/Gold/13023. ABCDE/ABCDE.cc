#include <iostream>
#include <vector>
using namespace std;
int N, M, ans;
vector<int> v[2001];
int check[2001] = { 0, };

void dfs(int st, int cnt) {
    if (cnt >= 5) {
        ans = 5;
        return;
    }
    for (int i = 0; i < v[st].size(); i++) {
        if (check[v[st][i]] == 0) {
            check[v[st][i]] = 1;
            dfs(v[st][i], cnt + 1);
            check[v[st][i]] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int to, from; cin >> to >> from;
        v[to].push_back(from);
        v[from].push_back(to);
    }
    ans = 0;
    for (int i = 0; i < N; i++) {
        //ans = 0;
        check[i] = 1;
        dfs(i, 1);
        if (ans == 5) {
            cout << "1";
            return 0;
        }
        check[i] = 0;
    }

    cout << "0";
    return 0;
}