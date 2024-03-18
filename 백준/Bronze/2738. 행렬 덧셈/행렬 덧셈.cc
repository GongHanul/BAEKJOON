#include <iostream>
using namespace std;
int N, M;
int map[101][101] = { 0, };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num; cin >> num;
			map[i][j] += num;
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}