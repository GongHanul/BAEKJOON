#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[501];
int check[501] = { 0, };
struct coord {
	int num, depth;
};
queue<coord> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, ans=0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, en; cin >> st >> en;
		v[st].push_back(en);
		v[en].push_back(st);
	}
	check[1] = 1;
	q.push({ 1, 0 });

	while (!q.empty()) {
		coord now = q.front(); q.pop();
		if (now.depth >= 2) continue;
		for (int i = 0; i < v[now.num].size(); i++) {
			if (check[v[now.num][i]] == 1) continue;
			check[v[now.num][i]] = 1;
			q.push({ v[now.num][i], now.depth+1 });
			ans++;
		}
		
	}

	cout << ans;

	return 0;
}