#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[10];

void dfs_f(int now) {
	if (now == -19) {
		return;
	}

	cout << char(now + 'A');
	dfs_f(v[now][0]);
	dfs_f(v[now][1]);
}

void dfs_s(int now) {
	if (now == -19) {
		return;
	}
	dfs_s(v[now][0]);
	cout << char(now + 'A');
	dfs_s(v[now][1]);
}

void dfs_t(int now) {
	if (now == -19) {
		return;
	}
	dfs_t(v[now][0]);
	dfs_t(v[now][1]);
	cout << char(now + 'A');
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char from, to1, to2;
		cin >> from >> to1 >> to2;
		from -= 'A';
		to1 -= 'A';
		to2 -= 'A';
		v[from].push_back(to1);
		v[from].push_back(to2);
	}

	dfs_f(0);
	cout << endl;
	dfs_s(0);
	cout << endl;
	dfs_t(0);

	return 0;
}