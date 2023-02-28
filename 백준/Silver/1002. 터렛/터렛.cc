#include <iostream>

using namespace std;

int x_1, y_1, r_1, x_2, y_2, r_2;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, ans; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		int num = (x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1);
		int r_p = (r_2 + r_1) * (r_2 + r_1);
		int r_n = (r_2 - r_1) * (r_2 - r_1);
		if (x_1 == x_2 && y_1 == y_2 && r_1 == r_2) ans = -1;
		else if (r_p == num || r_n == num) ans = 1;
		else if (r_p < num) ans = 0;
		else {
			if (num > r_n && num < r_p) ans = 2;
			else ans = 0;
		}
		 
		cout << ans << "\n";
	}

	return 0;
}