#include <iostream>
using namespace std;
char words[5][20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string sent;
	int maxx = -1;
	for (int i = 0; i < 5; i++) {
		cin >> sent;
		for (int j = 0; j < sent.size(); j++) {
			words[i][j] = sent[j];
		}
		int sent_size = sent.size();
		if (maxx < sent_size) {
			maxx = sent_size;
		}
	}

	for (int i = 0; i < maxx; i++) {
		for (int j = 0; j < 5; j++) {
			if (words[j][i] == '\0') continue;
			cout << words[j][i];
		}
	}

	return 0;
}