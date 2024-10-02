#include <iostream>
using namespace std;

long long arr[100001];
long long seg[100001 * 4];
long long lazy[100001 * 4];

void lazy_update(int x, int s, int e) {
	if (lazy[x]) {
		seg[x] += (e - s + 1) * lazy[x];
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				lazy[i] += lazy[x];
			}
		}
		lazy[x] = 0;
	}
}

long long update(int x, int s, int e, int l, int r, long long v) {
	lazy_update(x, s, e);
	if (r < s || e < l) return seg[x];
	if (l <= s && e <= r) {
		lazy[x] = v;
		lazy_update(x, s, e);
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, l, r, v) + update(x * 2 + 1, mid + 1, e, l, r, v);
}

long long get_sum(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return get_sum(x * 2, s, mid, l, r) + get_sum(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	update(1, 0, n - 1, 0, 0, arr[0]);
	for (int i = 1; i < n; i++) {
		update(1, 0, n - 1, i, i, arr[i] - arr[i - 1]);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			update(1, 0, n - 1, l, r, 1);
			update(1, 0, n - 1, r + 1, r + 1, -(r - l + 1));
		}
		else {
			int x;
			cin >> x;
			x--;
			cout << get_sum(1, 0, n - 1, 0, x) << '\n';
		}
	}
	return 0;
}