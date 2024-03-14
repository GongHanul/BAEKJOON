#include <iostream>
using namespace std;
long long N, M, tree[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	long long right = 0, left = 0, mid, sum, maxx=0;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (right < tree[i]) right = tree[i];
	}

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] <= mid) continue;
			sum += tree[i] - mid;
		}

		if (sum < M) {
			right = mid - 1;
		}
		else if (sum >= M) {
			maxx = mid;
			left = mid + 1;
		}
	}

	cout << maxx;

	return 0;
}