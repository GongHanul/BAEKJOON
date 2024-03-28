#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[5] = { 0, }, num = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		num += arr[i];
	}

	sort(arr, arr + 5);

	cout << num / 5 << "\n" << arr[2];

	return 0;
}