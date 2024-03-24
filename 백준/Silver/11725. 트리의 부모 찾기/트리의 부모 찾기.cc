#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int check[100001] = { 0, };

void dfs(int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (v[idx][i] == 1) continue;
		if (check[v[idx][i]] == 0) {
			check[v[idx][i]] = idx;
			dfs(v[idx][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, st, en; cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> st >> en;
		v[st].push_back(en);
		v[en].push_back(st);
	}

	for (int i = 1; i <= N; i++) {
		dfs(i);
	}

	for (int i = 2; i <= N; i++) {
		cout << check[i] << "\n";
	}
	

	return 0;
}