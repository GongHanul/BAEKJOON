#include <iostream>
#include <vector>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (1) {
		vector<int> v1, v2;
		int card, ans = 0, iter1 = 0, iter2 = 0;

		cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int i = 0; i < N; i++) {
			cin >> card;
			v1.push_back(card);
		}
		for (int i = 0; i < M; i++) {
			cin >> card;
			v2.push_back(card);
		}

		while (1) {
			if (iter1 == v1.size() || iter2 == v2.size()) break;

			if (v1[iter1] == v2[iter2]) {
				ans += 1;
				iter1++;
				iter2++;
			}
			else if (v1[iter1] < v2[iter2]) {
				iter1++;
			}
			else {
				iter2++;
			}

		}
		cout << ans <<"\n";
	}

	return 0;
}