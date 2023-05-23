#include <iostream>

using namespace std;

int N, M, H;
int map[31][11];
int ans;

int Check() {
	for (int j = 1; j <= N; j++) {
		int num = j; int nr = j;
		for (int i = 1; i <= H; i++) {
			num += map[i][nr];
			nr = num;
		}
		if (num != j) return 0;
	}
	return 1;
}

void simul(int st, int cnt) {
	if (cnt <= 3 && ans > cnt) {
		if (Check()) {
			ans = min(ans, cnt);
			return;
		}
		if (cnt == 3) return;
	}
    else return;

	for (int j = 1; j <= N; j++) {
		for (int i = st; i <= H; i++) {
			if (map[i][j] != 0 || map[i][j + 1] != 0) continue;
			map[i][j] = 1; map[i][j + 1] = -1;
			simul(i, cnt + 1);
			map[i][j] = 0; map[i][j + 1] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		map[a][b] = 1; map[a][b + 1] = -1;
	}
	ans = 213456789;
	simul(1, 0);
	
	if (ans > 3) ans = -1;
	cout << ans;
	return 0;
}