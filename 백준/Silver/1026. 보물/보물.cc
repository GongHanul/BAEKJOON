#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int a[55] = { 0, }, b[55] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}

	sort(a, a + N, compare);
	sort(b, b + N);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (a[i] * b[i]);
	}

	cout << ans;

	return 0;
}