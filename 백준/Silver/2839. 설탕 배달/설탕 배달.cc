#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N;
    cin >> N;
    int num = 0;

    while (N>=0) {
        if (N % 5 == 0) {
            num += N / 5;
            cout << num;
            return 0;
        }
        N -= 3;
        num++;
    }
    cout << -1;

    return 0;
}