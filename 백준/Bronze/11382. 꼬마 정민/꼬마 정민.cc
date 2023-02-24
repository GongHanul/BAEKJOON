#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long ans = 0;
	for (int i = 0; i < 3; i++) {
		long long num; cin >> num;
		ans += num;
	}

	cout << ans;

	return 0;
}