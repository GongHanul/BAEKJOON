#include <iostream>
using namespace std;
char map[55][55];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	int row = 0, col = 0, check;
	for (int i = 0; i < N; i++) {
		check = 1;
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'X') {
				check = 0; break;
			}
		}
		if (check) row += 1;
	}

	for (int i = 0; i < M; i++) {
		check = 1;
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 'X') {
				check = 0; break;
			}
		}
		if (check) col += 1;
	}

	cout << max(row, col);

	return 0;
}