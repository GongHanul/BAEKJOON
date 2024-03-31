#include <iostream>
#include <vector>
using namespace std;
int N, check[100001] = { 0, };
vector<char> vc;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> check[i];
	}
	v.push_back(0);
	for (int i = 1; i <= check[1]; i++) {
		v.push_back(i);
		vc.push_back('+');
	}
	int st = 1, maxx = check[1] + 1;
	while (v.size()>=0) {
		int now = v.back();
		if (now == 0 && maxx == N+1) break;
		else if (now == check[st]) {
			v.pop_back();
			vc.push_back('-');
			st += 1;
		}
		else if (now > check[st]) {
			cout << "NO\n";
			return 0;
		}
		else {
			v.push_back(maxx);
			vc.push_back('+');
			maxx += 1;
		}
	}

	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << "\n";
	}

	return 0;
}