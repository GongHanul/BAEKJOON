#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans;
int dat[4];
int map[16];
int maxv, minv;
vector<int> v;

void dfs(int cnt) {
	if (cnt == N-1) {
		int sum = map[0];
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				sum += map[i + 1];
			}
			else if (v[i] == 1) {
				sum -= map[i + 1];
			}
			else if (v[i] == 2) {
				sum *= map[i + 1];
			}
			else {
				sum /= map[i + 1];
			}
		}
		int de = 0;
		maxv = max(maxv, sum);
		minv = min(minv, sum);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (dat[i] > 0) {
			dat[i]--;
			v.push_back(i);
			dfs(cnt+1);
			dat[i]++;
			v.pop_back();
		}
	}
}

void init() {
	for (int i = 0; i < 4; i++) {
		dat[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		map[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> N;
		for (int i = 0; i < 4; i++) {
			cin >> dat[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}
		maxv = -987654321;
		minv = 987654321;
		dfs(0);
		cout << "#" << t << " " << maxv - minv << "\n";
	}
	return 0;
}