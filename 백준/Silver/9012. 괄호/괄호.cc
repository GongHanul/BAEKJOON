#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {

        string str;
        cin >> str;
        int ans = 0;
        for (int x = 0; x < 51; x++) {
            if (str[x] == '(') {
                ans += 1;
            }
            if (str[x] == ')') {
                ans -= 1;
            }
            if (ans < 0) {
                cout << "NO" << endl;
                break;
            }
            if (str[x] == '\0' && ans == 0) {
                cout << "YES" << endl;
                break;
            }
            if (str[x] == '\0') {
                if (ans == 0) {
                    cout << "YES" << endl;
                }
                else {
                    cout << "NO" << endl;
                }
                break;
            }
        }
    }

    return 0;
}