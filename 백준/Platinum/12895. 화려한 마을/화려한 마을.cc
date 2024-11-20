#include <iostream>
using namespace std;

int n, t, q;
int seg[100000 * 4];
int lazy[100000 * 4];

void lazy_update(int x, int s, int e) {
	if (lazy[x]) {
		seg[x] = lazy[x];
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				lazy[i] = lazy[x];
			}
		}
		lazy[x] = 0;
	}
}

int update(int x, int s, int e, int l, int r, int v) {
	lazy_update(x, s, e);
	if (r < s || e < l) return seg[x];
	if (l <= s && e <= r) {
		lazy[x] = v;
		lazy_update(x, s, e);
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, l, r, v) | update(x * 2 + 1, mid + 1, e, l, r, v);
}

int query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) | query(x * 2 + 1, mid + 1, e, l, r);
}

int calc(int x) {
	int cnt = 0;
	for (int i = 0; i < t; i++) {
		int y = (1 << i);
		if (x & y) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t >> q;
	update(1, 0, n - 1, 0, n - 1, 1);
	for (int i = 0; i < q; i++) {
		char cmd;
		int x, y;
		cin >> cmd >> x >> y;
		x--; y--;
		if (x > y) swap(x, y);
		if (cmd == 'C') {
			int v;
			cin >> v;
			v--;
			update(1, 0, n - 1, x, y, (1 << v));
		}
		else {
			cout << calc(query(1, 0, n - 1, x, y)) << '\n';
		}
	}
	return 0;
}