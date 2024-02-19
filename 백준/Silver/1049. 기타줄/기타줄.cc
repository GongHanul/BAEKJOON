#include <iostream>
using namespace std;
int guitar[55][5];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;
	int minx = 213456789, miny = 213456789;

	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		if (minx > x) minx = x;
		if (miny > y) miny = y;
	}

	int cnt = N / 6 + 1, val = 213456789;
	if (minx * cnt < val) val = minx * cnt;
	if (minx * (cnt - 1) + miny * (N % 6) < val) val = minx * (cnt - 1) + miny * (N % 6);
	if (miny * N < val) val = miny * N;

	cout << val;

	return 0;
}