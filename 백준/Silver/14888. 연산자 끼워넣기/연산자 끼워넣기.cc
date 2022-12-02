#include <iostream>
#include <vector>
using namespace std;

int N, maxx, minn;
int num[15], OP[5];
vector<int> check;

void dfs(int cnt) {
	if (cnt == N - 1) {
		int sum = num[0];
		for (int i = 0; i < N - 1; i++) {
			if (check[i] == 0)
				sum += num[i + 1];
			else if (check[i] == 1)
				sum -= num[i + 1];
			else if (check[i] == 2)
				sum *= num[i + 1];
			else
				if (sum < 0) {
					sum *= -1;
					sum /= num[i + 1];
					sum *= -1;
				}
				else
					sum /= num[i + 1];
		}
		minn = min(minn, sum);
		maxx = max(maxx, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (OP[i] > 0) {
			check.push_back(i);
			OP[i] -= 1;
			dfs(cnt + 1);
			check.pop_back();
			OP[i] += 1;
		}
	}
}

int main() {
	cin >> N;
	check.clear();
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> OP[i];
	maxx = -1e9, minn = 1e9;
	dfs(0);

	cout << maxx << "\n" << minn << "\n";

	return 0;
}