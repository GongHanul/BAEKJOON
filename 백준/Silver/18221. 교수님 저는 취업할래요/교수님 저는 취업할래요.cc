#include <iostream>
using namespace std;
int N;
int map[1001][1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int ra=-1, ca=-1, rb=-1, cb=-1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 5) {
				ra = i, ca = j;
			}
			if (map[i][j] == 2) {
				rb = i, cb = j;
			}
		}
	}

	// distance
	if ((ra - rb) * (ra - rb) + (ca - cb) * (ca - cb) < 25) {
		cout << 0;
		return 0;
	}

	int max_r = max(ra, rb), min_r = min(ra, rb);
	int max_c = max(ca, cb), min_c = min(ca, cb);

	int student = 0;
	if (ra == rb) {
		for (int i = min_c; i <= max_c; i++) {
			if (map[ra][i] == 1) student += 1;
		}
	}
	else if (ca == cb) {
		for (int i = min_r; i <= max_r; i++) {
			if (map[i][ca] == 1) student += 1;
		}
	}
	if (student >= 3) {
		cout << 1;
		return 0;
	}

	student = 0;
	for (int i = min_r; i <= max_r; i++) {
		for (int j = min_c; j <= max_c; j++) {
			if (map[i][j] == 1) student += 1;
		}
	}

	if (student < 3) {
		cout << 0;
	}
	else {
		cout << 1;
	}

	return 0;
}