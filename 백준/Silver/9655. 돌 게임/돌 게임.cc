#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, cnt = 0; cin >> N;

	while (1) {
		if (N > 3) {
			N -= 3;
		}
		else {
			N -= 1;
		}

		cnt += 1;
		if (N == 0) break;
	}

	if (cnt % 2 == 0) cout << "CY";
	else cout << "SK";


	return 0;
}