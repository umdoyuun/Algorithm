#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> lis;

int lower_bound(int s, int e, int x) {
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (lis[mid] < x) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	lis.reserve(n);
	int x;
	cin >> x;
	lis.push_back(x);
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (*lis.rbegin() < x) {
			lis.push_back(x);
		}
		else {
			int pos = lower_bound(0, lis.size(), x);
			lis[pos] = x;
		}
	}
	int res = lis.size();
	cout << res;
	return 0;
}