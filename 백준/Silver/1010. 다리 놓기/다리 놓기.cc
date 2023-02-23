#include <iostream>

using namespace std;

//long long factorial(int val) {
//	if (val <= 1) return 1;
//	else return val * factorial(val - 1);
//}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int B1, B2; cin >> B1 >> B2;
		int B3 = B2 - B1;
		/*cout << factorial(B2) / (factorial(B1) * factorial(B3)) << "\n";*/
		int ans = 1, temp = 1;
		for (int i = B2; i > B2 - B1; i--) {
			ans = ans * i;
			ans = ans / temp;
			temp++;
		}
		cout << ans << "\n";
	}
	
	return 0;
}