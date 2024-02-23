#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}

