#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n - 1; j++) cout << ' ';
		for (int j = 0; j < 1 + 2 * i; j++) cout << '*';
		cout << '\n';
	}
	return 0;
}