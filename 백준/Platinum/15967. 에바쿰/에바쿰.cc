#include <iostream>
using namespace std;

int n, m, k;
int arr[1000001];
long long seg[1000001 * 4];
long long lazy[1000001 * 4];

long long init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = arr[s];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

void lazy_update(int x, long long s, long long e) {
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

long long update(int x, int s, int e, int l, int r, long long value) {
	lazy_update(x, s, e);
	if (r < s || e < l) return seg[x];
	if (l <= s && e <= r) {
		lazy[x] += value;
		lazy_update(x, s, e);
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, l, r, value) + update(x * 2 + 1, mid + 1, e, l, r, value);
}

long long query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (register int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	for (register int i = 0; i < m + k; i++) {
		int cmd, x, y;
		long long v;
		cin >> cmd >> x >> y;
		x--;y--;
		if (cmd == 1) {
			cout << query(1, 0, n - 1, x, y) << '\n';
		}
		else {
			cin >> v;
			update(1, 0, n - 1, x, y, v);
		}
	}
	return 0;
}