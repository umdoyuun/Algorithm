#include <iostream>
using namespace std;

int n, m;
long long seg[1000000 * 4];

long long update(int x, int s, int e, int idx, long long cost) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) {
		return seg[x] += cost;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, cost) + update(x * 2 + 1, mid + 1, e, idx, cost);
}

long long query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cmd, x, y;
		long long cost;
		cin >> cmd;
		if (cmd == 1) {
			cin >> x >> cost;
			x--;
			update(1, 0, n - 1, x, cost);
		}
		else {
			cin >> x >> y;
			x--, y--;
			cout << query(1, 0, n - 1, x, y) << '\n';
		}
	}
	return 0;
}