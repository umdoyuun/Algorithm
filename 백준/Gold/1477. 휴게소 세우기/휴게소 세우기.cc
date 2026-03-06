#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> v;

bool check(int x) {
	int cnt = m, cur = 0;
	for (auto next : v) {
		while (cur + x < next) {
			if (!cnt) return false;
			cur += x;
			cnt--;
		}
		cur = next;
	}
	return true;
}

int parametricSearch(int s, int e) {
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (check(mid)) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	v.push_back(k);
	sort(v.begin(), v.end());
	int res = parametricSearch(0, k);
	cout << res << '\n';
	return 0;
}