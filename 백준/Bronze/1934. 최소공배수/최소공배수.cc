#include <iostream>
using namespace std;

int euclidean(int a, int b) {
	if (b == 0) return a;
	else {
		return euclidean(b, a % b);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, A, B, ans; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> A >> B;
		ans = A * B / euclidean(A, B);
		cout << ans << "\n";
	}

	return 0;
}