#include <iostream>
#include <algorithm>
using namespace std;
int N, M, num;
int check[100001] = { 0, };

void binary_search(int num) {
	int left = 0, mid = 0, right = N - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		if (check[mid] == num) {
			cout << 1 << "\n";
			return;
		}
		else if (check[mid] > num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << 0 << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> check[i];
	}

	sort(check, check + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		binary_search(num);
	}

	return 0;
}