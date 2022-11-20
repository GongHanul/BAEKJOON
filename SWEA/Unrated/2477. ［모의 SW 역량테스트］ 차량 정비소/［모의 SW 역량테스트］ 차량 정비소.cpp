#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int rec, rep, time;
};

int N, M, K, A, B;
int rec[10], An[10], Am[10];
int rep[10], Bn[10], Bm[10];
Node cus[1001];

void simul() {
	int t = 0, out = 0;
	memset(An, -1, sizeof(An));
	memset(Bn, -1, sizeof(Bn));

	queue<int> q1, q2;
	while (1) {
		for (int i = 1; i <= K; i++) {
			if (cus[i].time == t) q1.push(i);
		}
		for (int i = 1; i <= N; i++) {
			if (An[i] == t) {
				An[i] = -1;
				q2.push(Am[i]);
			}
		}
		for (int i = 1; i <= N; i++) {
			if (q1.empty()) continue;
			if (An[i] == -1) {
				An[i] = rec[i] + t;
				Am[i] = q1.front();
				cus[q1.front()].rec = i;
				q1.pop();
			}
		}

		for (int i = 1; i <= M; i++) {
			if (Bn[i] == t) {
				Bn[i] = -1;
				out += 1;
			}
		}
		for (int i = 1; i <= M; i++) {
			if (q2.empty()) continue;
			if (Bn[i] == -1) {
				Bn[i] = rep[i] + t;
				Bm[i] = q2.front();
				cus[q2.front()].rep = i;
				q2.pop();
			}
		}

		if (out == K) break;
		t++;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++) cin >> rec[i];
		for (int i = 1; i <= M; i++) cin >> rep[i];
		for (int i = 1; i <= K; i++) cin >> cus[i].time;

		simul();
		int ans = 0;
		for (int i = 1; i <= K; i++) {
			if (cus[i].rec == A && cus[i].rep == B) ans += i;
		}
        if(ans == 0) ans = -1;
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}