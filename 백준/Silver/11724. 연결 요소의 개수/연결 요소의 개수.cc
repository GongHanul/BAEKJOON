#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> v[1001];
int visited[1001] = { 0, };

void dfs(int num) {
	visited[num] = 1;
		for (int i = 0; i < v[num].size(); i++) {
		int idx = v[num][i];
		if (visited[idx] == 0) {
			dfs(idx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int st, en, cnt=0;
	for (int i = 0; i < M; i++) {
		cin >> st >> en;
		v[st].push_back(en);
		v[en].push_back(st);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			cnt += 1;
			dfs(i);
		}
	}
	cout << cnt;
	return 0;
}