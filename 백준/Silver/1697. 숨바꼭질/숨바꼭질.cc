#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;
struct Node {
	int c, step;
};
int map[MAX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;
	queue<Node> q;
	q.push({ N, 0 });

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.c == K) {
			cout << now.step;
			break;
		}

		if (now.c - 1 >= 0) {
			if (map[now.c - 1] == 0) {
				map[now.c - 1] = now.step + 1;
				q.push({ now.c - 1, now.step + 1 });
			}
			
		}
		if (now.c + 1 < MAX) {
			if (map[now.c + 1] == 0) {
				map[now.c + 1] = now.step + 1;
				q.push({ now.c + 1, now.step + 1 });
			}
		}
		if (now.c * 2 < MAX) {
			if (map[now.c * 2] == 0) {
				map[now.c * 2] = now.step + 1;
				q.push({ now.c * 2, now.step + 1 });
			}
		}
		
	}

	return 0;
}