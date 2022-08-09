#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int arr[25][25];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int n;
int visited[25][25] = { 0, };
int cnt;
vector<int> cnt_vec;

void dfs(int row, int col) {
	visited[row][col] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int n_row = row + dr[i];
		int n_col = col + dc[i];
		if (n_row < 0 || n_row >= n || n_col < 0 || n_col >= n) continue;
		if (arr[n_row][n_col] == 0) continue;
		if (visited[n_row][n_col] != 0) continue;
		//visited[n_row][n_col] = 1;
		//cnt++;
		dfs(n_row, n_col);
	}
}

int main() {

	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				cnt = 0;
				dfs(i, j);
				cnt_vec.push_back(cnt);

			}
		}
	}

	sort(cnt_vec.begin(), cnt_vec.end());
	cout << cnt_vec.size() << endl;
	for (int i = 0; i < cnt_vec.size(); i++) {
		cout << cnt_vec[i] << endl;
	}

	return 0;
}