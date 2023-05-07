#include <iostream>

using namespace std;

long long dp[65][10];
int dp_sum[65];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
		//dp_sum[1] += dp[1][i];
	}

	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			//dp_sum[i] += dp[i][j];
		}
	}

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n; cin >> n;
		long long ans = 0;
		for (int i = 0; i <= 9; i++) {
			//ans += dp_sum[i];
			ans += dp[n][i];
		}
		cout << ans << "\n";
	}

	return 0;
}