#include <iostream>
using namespace std;

int n, m;
int seg[500000 * 4];

int update(int x, int s, int e, int idx, int value) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) {
		return seg[x] += value;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, value) + update(x * 2 + 1, mid + 1, e, idx, value);
}

int query(int x, int s, int e, int idx) {
	if (s == e) return s + 1;
	int mid = s + (e - s) / 2;
	if (idx <= seg[x * 2]) return query(x * 2, s, mid, idx);
	return query(x * 2 + 1, mid + 1, e, idx - seg[x * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		update(1, 0, n - 1, i, x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, x, y;
		cin >> cmd;
		if (cmd == 1) {
			cin >> x >> y;
			update(1, 0, n - 1, x - 1, y);
		}
		else {
			cin >> x;
			cout << query(1, 0, n - 1, x) << '\n';
		}
	}
	return 0;
}