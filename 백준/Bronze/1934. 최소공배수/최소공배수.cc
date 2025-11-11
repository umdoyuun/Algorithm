#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		int e = x * y;
		int ret = 0;
		for (int i = y; i <= e; i += y) {
			if (i % x == 0) {
				ret = i;
				break;
			}
		}
		cout << ret << '\n';
	}
	return 0;
}