#include <iostream>
#include <vector>
using namespace std;

int N, ans;
int map[25][25];
int check[25];

void simul(int idx, int cnt) {
	if (cnt == N / 2) {
		vector<int> v1, v2;
		for (int i = 0; i < N; i++) {
			if (check[i] == 1) v1.push_back(i);
			else v2.push_back(i);
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < v1.size()-1; i++) {
			for (int j = i+1; j < v1.size(); j++) {
				sum1 += map[v1[i]][v1[j]] + map[v1[j]][v1[i]];
				sum2 += map[v2[i]][v2[j]] + map[v2[j]][v2[i]];
			}
		}
		ans = min(ans, abs(sum1 - sum2));
		return;
	}

	for (int i = idx; i < N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			simul(i, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	ans = 1e9;
	simul(0, 0);

	cout << ans << "\n";
}