#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int x, y, dist;
};
int N, M, chicken_num, ans;
int check[15] = { 0, };
vector<Node> chicken, home;

int calc() {
	int dist = 0, sum = 0;
	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			if (check[j] == 1) {
				dist = abs(home[i].x - chicken[j].x) + abs(home[i].y - chicken[j].y);
				if (home[i].dist > dist) home[i].dist = dist;
			}
		}
	}
	for (int i = 0; i < home.size(); i++) {
		sum += home[i].dist;
		home[i].dist = 1e9;
	}

	return sum;
}

void dfs(int st, int cnt) {
	if (cnt == M) {
		// 집 별로 각 치킨집에 따른 거리 중 가장 적은 거리 출력
		ans = min(ans, calc());
		return;
	}

	for (int i = st; i < chicken.size(); i++) {
		if (check[i] == 0) {
			check[i] = 1;
			dfs(i+1, cnt+1);
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	chicken_num = 0, ans = 1e9;
	int dist = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			if (num == 1) {
				home.push_back({ i, j, dist });
			}
			if (num == 2) {
				chicken.push_back({ i, j, 0 });
			}
		}
	}
	dfs(0, 0);

	cout << ans;

	return 0;
}