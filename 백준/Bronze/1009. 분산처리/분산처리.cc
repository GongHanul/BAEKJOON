#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ans;
	for (int i = 1; i < 10; i++) {
		ans = 1;
		for (int j = 1; j < 10; j++) {
			ans = (ans * i) % 10;
			if (v[i].size() == 0) {
				v[i].push_back(ans);
				continue;
			}
			if (find(v[i].begin(), v[i].end(), ans) != v[i].end()) {
				break;
			}
			v[i].push_back(ans);

		}
	}

	int N, a, b;
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		if (a % 10 == 0) {
			cout << 10 << "\n";
			continue;
		}
		a %= 10;
		if (b == 1) {
			cout << a << "\n";
			continue;
		}
		int step = b % v[a].size() - 1;
		if (step < 0) step = v[a].size() - 1;
		cout << v[a][step] << "\n";
	}

	return 0;
}