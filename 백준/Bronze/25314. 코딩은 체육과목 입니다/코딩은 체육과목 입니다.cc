#include <iostream>
using namespace std;

int N;
string n_long = "long ";

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N / 4; i++) {
		cout << n_long;
	}

	cout << "int";

	return 0;
}