#include <iostream>
#include <vector>
#include <queue>

#define MAX 20001
#define INF 2134567890
using namespace std;

int V, E, start;
vector<pair<int, int>> a[MAX];
int d[MAX];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push(make_pair(0, start));

	while (pq.empty() == 0) {
		int current = pq.top().second;
		int cDistance = -pq.top().first;
		pq.pop();

		if (d[current] < cDistance) continue;

		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nDistance = a[current][i].second;
			if (nDistance + cDistance < d[next]) {
				d[next] = nDistance + cDistance;
				pq.push(make_pair(-d[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> start;
	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < E; i++) {
		int v1, v2, e;
		cin >> v1 >> v2 >> e;
		a[v1].push_back(make_pair(v2, e));
	}

	dijkstra();

	return 0;
}