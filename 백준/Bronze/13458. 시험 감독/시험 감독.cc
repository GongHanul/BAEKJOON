#include <iostream>
#include <vector>
using namespace std;

int main() {
	long N;
	vector<long> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long num; cin >> num;
		v.push_back(num);
	}
	long ins1, ins2; cin >> ins1 >> ins2;
	long ans = N;
	for (int i = 0; i < v.size(); i++) {
		int sum1 = v[i] - ins1;
		if (sum1 > 0) {
			int sum2 = sum1 / ins2;
			if (sum1%ins2 > 0) ans += sum2 + 1;
			else ans += sum2;
		}
	}

	cout << ans << "\n";

	return 0;
}