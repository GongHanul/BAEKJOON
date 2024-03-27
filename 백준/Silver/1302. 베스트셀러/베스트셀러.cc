#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
string str, ans;
map<string, int> book;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, maxx=0; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		book[str]++;
	}
	
	for (auto best : book) {
		if (best.second > maxx) {
			maxx = best.second;
			ans = best.first;
		}
	}

	cout << ans;

	return 0;
}