#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	string str;
	stack<int> s;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str.compare("push") == 0) {
			int num; cin >> num;
			s.push(num);
		}
		else if (str.compare("pop") == 0) {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (str.compare("top") == 0) {
			if (!s.empty()) {
				cout << s.top() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (str.compare("size") == 0) {
			cout << s.size() << "\n";
		}
		else if (str.compare("empty") == 0) {
			cout << s.empty() << "\n";
		}
	}

	return 0;
}