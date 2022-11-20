#include <iostream>
#include <vector>
using namespace std;

int N, ans;
int map[16][16];
int check[16];

void simul(int idx, int cnt) {
	if (cnt == N/2) {
		vector<int> f1, f2;
		for (int i = 0; i < N; i++) {
			if (check[i] == 1) f1.push_back(i);
			else f2.push_back(i);
		}
		int f1_food = 0, f2_food = 0;
		for (int i = 0; i < f1.size() - 1; i++) {
			for (int j = i + 1; j < f1.size(); j++) {
				f1_food += map[f1[i]][f1[j]] + map[f1[j]][f1[i]];
				f2_food += map[f2[i]][f2[j]] + map[f2[j]][f2[i]];
			}
		}
		ans = min(ans, abs(f1_food - f2_food));
		return;
	}

	for (int i = idx; i < N; i++) {
		if (check[i] != 0) continue;
		check[i] = 1;
		simul(i, cnt+1);
		check[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = 987654321;
		simul(0, 0);
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}