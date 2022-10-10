#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
int map[16][16];
int dat[16] = { 0, };

void dfs(int index, int cnt) {
	if (cnt == N / 2) {
		vector<int> vA, vB;
		int fA = 0, fB = 0;
		for (int i = 0; i < N; i++) {
			if (dat[i] == 1) vA.push_back(i);
			else vB.push_back(i);
		}
		for (int i = 0; i < vA.size() - 1; i++) {
			for (int j = i+1; j < vA.size(); j++) {
				fA += map[vA[i]][vA[j]] + map[vA[j]][vA[i]];
				fB += map[vB[i]][vB[j]] + map[vB[j]][vB[i]];
			}
		}
		ans = min(ans, abs(fA - fB));
	}
	for (int i = index; i < N; i++) {
		if (dat[i] == 0) {
			dat[i] = 1;
			dfs(i, cnt + 1);
			dat[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = 987654321;
		dfs(0, 0);
        cout<<"#"<<t<<" "<<ans<<"\n";
	}
	return 0;
}