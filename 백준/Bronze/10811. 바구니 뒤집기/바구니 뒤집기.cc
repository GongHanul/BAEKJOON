#include <iostream>
#include <vector>
using namespace std;
int v1[110], v2[110];
int N, M, i, j;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		v1[n] = n;
	}

	for (int n = 0; n < M; n++) {
		cin >> i >> j;

		for (int step = i; step <= j; step++) {
			v2[step] = v1[step];
		}

		for (int step = i; step <= j; step++) {
			v1[step] = v2[j - step + i];
		}
	}
	
	for (int n = 1; n < N + 1; n++) {
		cout << v1[n] << " ";
	}

	return 0;
}