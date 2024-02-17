#include <iostream>
using namespace std;

int map[10][10] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int r = 1; r < 10; r++) {
		for (int c = 1; c < 10; c++) {
			cin >> map[r][c];
		}
	}

	int maxx = -1, maxr = -1, maxc = -1;

	for (int r = 1; r < 10; r++) {
		for (int c = 1; c < 10; c++) {
			if (map[r][c] > maxx) {
				maxx = map[r][c];
				maxr = r;
				maxc = c;
			}
		}
	}

	cout << maxx << "\n";
	cout << maxr << " " << maxc;

	return 0;
}