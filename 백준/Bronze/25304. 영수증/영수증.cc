#include <iostream>
using namespace std;

int main() {
	int t, n, x, y;
	cin >> t >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		sum += x * y;
	}
	if (sum == t) cout << "Yes\n";
	else cout << "No\n";
}