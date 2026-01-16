#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> lis;

void init() {
	lis.clear();
	lis.reserve(n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n) {
		init();
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			auto pos = lower_bound(lis.begin(), lis.end(), x);
			if (pos == lis.end()) {
				lis.push_back(x);
			}
			else {
				*pos = x;
			}
		}
		cout << lis.size() << '\n';
	}
	return 0;
}