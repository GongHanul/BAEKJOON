#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[101];
int used[101] = { 0, };
int ans = 0;
void dfs(int now) {

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (used[next] != 0) continue;
		used[next] = 1;
		ans++;
		dfs(next);
	}

}

int main() {
	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;
	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	used[1] = 1;
	dfs(1);
	cout << ans;

	return 0;
}