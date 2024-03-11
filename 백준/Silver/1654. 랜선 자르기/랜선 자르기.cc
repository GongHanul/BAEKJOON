#include <iostream>
#include <algorithm>
using namespace std;
int K, N;
long rope[10001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	long right = -1;
	for (int i = 0; i < K; i++) {
		cin >> rope[i];
		right = max(right, rope[i]);
	}

	long left = 1, mid = 0, maxx = 0, ans;
	while (left<=right) {
		mid = (left + right) / 2;
		
		ans = 0;
		for (int i = 0; i < K; i++) {
			ans += (rope[i] / mid);
		}

		if (ans < N) {
			right = mid - 1;
		}
		else if (ans >= N) {
			left = mid + 1;
			maxx = max(maxx, mid);
		}

	}

	cout << maxx;

	return 0;
}