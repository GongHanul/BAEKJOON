#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x_1, y_1, x_2, y_2;

int calc(int x, int y, int r) {
	int d_1 = 0, d_2 = 0, d_3 = 0, d_4 = 0;

	if ((x_1 - x) * (x_1 - x) + (y_1 - y) * (y_1 - y) < r * r) {
		d_1 = 1;
		if ((x_2 - x) * (x_2 - x) + (y_2 - y) * (y_2 - y) > r * r) {
			d_2 = 1;
			return 1;
		}
	}
	if ((x_2 - x) * (x_2 - x) + (y_2 - y) * (y_2 - y) < r * r) {
		d_3 = 1;
		if ((x_1 - x) * (x_1 - x) + (y_1 - y) * (y_1 - y) > r * r) {
			d_4 = 1;
			return 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cin >> N;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int cx, cy, r; cin >> cx >> cy >> r;
			ans += calc(cx, cy, r);
		}

		cout << ans << "\n";
	}

	return 0;
}