#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];

int sum_card(vector<int> v) {
	int maxx = -1, sum = 0;
	for (int i = 0; i < v.size() - 2; i++) {
		for (int j = i+1; j < v.size() - 1; j++) {
			for (int k = j+1; k < v.size(); k++) {
				sum = (v[i] + v[j] + v[k])%10;
				if (maxx < sum) maxx = sum;
			}
		}
	}
	return maxx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, card; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> card;
			v[i].push_back(card);
		}
	}
	int card_max = -1, ans = -1;
	for (int i = 0; i < N; i++) {
		if (card_max <= sum_card(v[i])) {
			card_max = sum_card(v[i]);
			ans = i;
		}
	}

	cout << ans+1;

	return 0;
}