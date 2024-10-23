#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d;
	long long res = -1e15;
	deque<pair<int, long long>> dq;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		while (!dq.empty()) {
			if (dq.front().first + d < i) dq.pop_front();
			else break;
		}
		if(!dq.empty() && dq.front().second > 0)
			x = dq.front().second + x;
		while (!dq.empty()) {
			if (dq.back().second < x) {
				dq.pop_back();
				
			}
			else break;
		}
		res = max(x, res);
		dq.push_back({i, x});
		/*for (int i = 0; i < dq.size(); i++) {
			cout << dq[i].second << ' ';
		}
		cout << '\n';*/
	}
	cout << res;
	return 0;
}