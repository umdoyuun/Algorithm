#include <iostream>
using namespace std;
#define Max 1000001

int n;
int seg[1000001 * 4];

int update(int x, int s, int e, int idx, int diff) {
	if (idx < s || idx > e) return seg[x];
	if (s == e) {
		return seg[x] += diff;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, diff) + update(x * 2 + 1, mid + 1, e, idx, diff);
}

int query(int x, int s, int e, int k) {
	if (s == e) return s;
	int mid = s + (e - s) / 2;
	int cnt = seg[x * 2];
	if (k <= cnt) return query(x * 2, s, mid, k);
	else return query(x * 2 + 1, mid + 1, e, k - cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (register int i = 0; i < n; i++) {
		int cmd, x, y;
		cin >> cmd;
		if (cmd == 1) {
			cin >> x;
			int res = query(1, 0, Max - 1, x);
			cout << res << '\n';
			update(1, 0, Max - 1, res, -1);
		}
		else {
			cin >> x >> y;
			update(1, 0, Max - 1, x, y);
		}
	}
	
	return 0;
}