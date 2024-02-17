#include <iostream>
using namespace std;

int main() {
    int student[50] = { 0, };
	int N;
	for (int i = 0; i < 28; i++) {
		cin >> N;
		student[N] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (student[i] == 0) {
			cout << i << "\n";
		}
	}

	return 0;
}