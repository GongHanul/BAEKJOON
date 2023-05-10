#include <iostream>
using namespace std;

struct Node {
	int j, o, i;
};
int N, M, K;
Node map[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		string str; cin >> str;
		for (int j = 1; j <= M; j++) {
			if (str[j - 1] == 'J') map[i][j].j += 1;
			else if (str[j - 1] == 'O') map[i][j].o += 1;
			else map[i][j].i += 1;
			map[i][j].j += map[i - 1][j].j + map[i][j - 1].j - map[i - 1][j - 1].j;
			map[i][j].o += map[i - 1][j].o + map[i][j - 1].o - map[i - 1][j - 1].o;
			map[i][j].i += map[i - 1][j].i + map[i][j - 1].i - map[i - 1][j - 1].i;
		}
	}

	for (int i = 0; i < K; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << map[c][d].j - map[a - 1][d].j - map[c][b - 1].j + map[a - 1][b - 1].j << " ";
		cout << map[c][d].o - map[a - 1][d].o - map[c][b - 1].o + map[a - 1][b - 1].o << " ";
		cout << map[c][d].i - map[a - 1][d].i - map[c][b - 1].i + map[a - 1][b - 1].i << "\n";

	}


	return 0;
}