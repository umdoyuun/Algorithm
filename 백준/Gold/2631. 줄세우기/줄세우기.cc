#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n;
deque<int> lis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
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
	cout << n - lis.size();
	return 0;
}