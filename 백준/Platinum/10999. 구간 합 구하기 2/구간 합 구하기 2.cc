#include <iostream>
using namespace std;

int n, m, k;
long long arr[1000001];
long long seg[1000001 * 4];
long long lazy[1000001 * 4];

long long init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = arr[s];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		seg[x] += (e - s + 1) * lazy[x];
		if (s != e) {
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}

void update_range(int x, int s, int e, int l, int r, long long diff) {
	update_lazy(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		seg[x] += (e - s + 1) * diff;
		if (s != e) {
			lazy[x * 2] += diff;
			lazy[x * 2 + 1] += diff;
		}
		return;
	}
	int mid = s + (e - s) / 2;
	update_range(x * 2, s, mid, l, r, diff);
	update_range(x * 2 + 1, mid + 1, e, l, r, diff);
	seg[x] = seg[x * 2] + seg[x * 2 + 1];
}

long long get_sum(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
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
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n-1);
	for (int i = 0; i < m + k; i++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			long long value;
			cin >> value;
			update_range(1, 0, n - 1, x- 1, y - 1, value);
		}
		else {
			cout << get_sum(1, 0, n - 1, x - 1, y - 1) << '\n';
		}
	}
	return 0;
}