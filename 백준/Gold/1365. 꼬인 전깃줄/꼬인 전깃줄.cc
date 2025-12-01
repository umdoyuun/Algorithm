#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<int> lis;
	cin >> n;
	lis.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		auto pos = lower_bound(lis.begin(), lis.end(), x);
		if (pos == lis.end()) {
			lis.push_back(x);
		}
		else {
			*pos = x;
		}
	}
	int res = n - lis.size();
	cout << res;
	return 0;
}