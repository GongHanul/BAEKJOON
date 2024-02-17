#include <iostream>
using namespace std;

int N, M, i, j;
int v[110];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		v[n] = n;
	}

	for (int n = 0; n < M; n++) {
		cin >> i >> j;
		int temp = v[j];
		v[j] = v[i];
		v[i] = temp;
	}

	for (int n = 1; n <= N; n++) {
		cout << v[n] << " ";
	}

	return 0;
}