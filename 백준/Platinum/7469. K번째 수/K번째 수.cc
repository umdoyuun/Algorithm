#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
pair<int, int> pii[100001];
vector<int> v[100001 * 4];

void update(int x, int s, int e, int idx, int value) {
	if (idx < s || idx > e) return;
	v[x].push_back(value);
	if (s == e) return;
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, idx, value);
	update(x * 2 + 1, mid + 1, e, idx, value);
}

int query(int x, int s, int e, int l, int r, int k) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return (int)(lower_bound(v[x].begin(), v[x].end(), k) - v[x].begin());
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r, k) + query(x * 2 + 1, mid + 1, e, l, r, k);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> pii[i].first;
		pii[i].second = i;
	}
	sort(pii, pii + n);
	for (int i = 0; i < n; i++) {
		update(1, 0, n - 1, pii[i].second, pii[i].first);
	}
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--;
		int s = -1e9, e = 1e9;
		while (s <= e) {
			int mid = s + (e - s) / 2;
			int ret = query(1, 0, n - 1, l, r, mid);
			if (ret >= x) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		cout << e << '\n';
	}
	return 0;
}