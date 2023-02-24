#include <iostream>
#include <algorithm>
using namespace std;

int dat[201];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		dat[num+100]++;
	}

	int v; cin >> v;
	cout << dat[v+100];

	return 0;
}