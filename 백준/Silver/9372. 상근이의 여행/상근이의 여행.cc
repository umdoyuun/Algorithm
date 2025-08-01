#include <iostream>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
		}
		cout << n - 1 << '\n';
	}
	return 0;
}