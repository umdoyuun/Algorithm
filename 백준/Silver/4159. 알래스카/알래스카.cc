#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

void init() {
	v.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> n;
		if (!n) break;
		init();
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
			v.push_back(2844 - x);
		}
		sort(v.begin(), v.end());
		int dist = 0;
		for (int x : v) {
			if (dist >= x) {
				dist = x + 200;
			}
			else {
				break;
			}
		}
		if (dist < 2844) cout << "IMPOSSIBLE\n";
		else cout << "POSSIBLE\n";
	}
	return 0;
}