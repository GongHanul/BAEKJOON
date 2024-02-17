#include <iostream>
using namespace std;
int v1[110];
int N, M, i, j, temp = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		v1[n] = n;
	}

	for (int n = 0; n < M; n++) {
		cin >> i >> j;

		int step = (j - i) / 2 + 1;

		for (int cnt = 0; cnt < step; cnt++) {
			temp = v1[j - cnt];
			v1[j - cnt] = v1[i + cnt];
			v1[i + cnt] = temp;
		}
	}
	
	for (int n = 1; n < N + 1; n++) {
		cout << v1[n] << " ";
	}

	return 0;
}