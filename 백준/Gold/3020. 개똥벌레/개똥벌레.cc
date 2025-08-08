#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, h;
vector<int> bottom, top;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++) {
		int x, y;
		cin >> x >> y;
		bottom.push_back(x);
		top.push_back(y);
	}
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());
	int mn = n, cnt = 0;
	for (int i = 1; i <= h; i++) {
		int crash = (top.end() - lower_bound(top.begin(), top.end(), i)) + (bottom.end() - lower_bound(bottom.begin(), bottom.end(), h - i + 1));

		if (crash < mn) {
			cnt = 1;
			mn = crash;
		}
		else if (crash == mn) {
			cnt++;
		}
	}
	cout << mn << ' ' << cnt << '\n';
	return 0;
}