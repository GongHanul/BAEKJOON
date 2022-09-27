#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int a = 0, b = 0, new_N = 0, num=0, old_N = 0;
	if (N == 0) {
		cout << 1;
		return 0;
	}
	old_N = N;
	while (1) {
		a = old_N / 10;
		b = old_N % 10;
		new_N = b * 10 + ((a + b)%10);
		num += 1;
		if (N == new_N) {
			break;
		}
		old_N = new_N;
	}
	cout << num;

	return 0;
}