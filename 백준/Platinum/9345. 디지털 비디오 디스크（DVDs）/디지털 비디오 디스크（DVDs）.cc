#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int mx, mn;
};

int n, m;
int arr[100001];
node seg[100001 * 4];

void init(int x, int s, int e) {
	if(s == e) {
		seg[x] = { s, s, };
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x].mx = max(seg[x * 2].mx, seg[x * 2 + 1].mx);
	seg[x].mn = min(seg[x * 2].mn, seg[x * 2 + 1].mn);
}

void update(int x, int s, int e, int idx, int value) {
	if (idx < s || e < idx) return;
	if (s == e) {
		seg[x] = { value, value };
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, idx, value);
	update(x * 2 + 1, mid + 1, e, idx, value);
	seg[x].mx = max(seg[x * 2].mx, seg[x * 2 + 1].mx);
	seg[x].mn = min(seg[x * 2].mn, seg[x * 2 + 1].mn);
}

node query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return { 0, n };
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	node a = query(x * 2, s, mid, l, r);
	node b = query(x * 2 + 1, mid + 1, e, l, r);
	return { max(a.mx, b.mx), min(a.mn, b.mn) };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (register int i = 0; i < n; i++) arr[i] = i;
		init(1, 0, n - 1);
		for (register int i = 0; i < m; i++) {
			int cmd, x, y;
			cin >> cmd >> x >> y;
			if (cmd) {
				node ret = query(1, 0, n - 1, x, y);
				if (ret.mx == y && ret.mn == x) cout << "YES\n";
				else cout << "NO\n";
			}
			else {
				int tmp = arr[x];
				arr[x] = arr[y];
				arr[y] = tmp;
				update(1, 0, n - 1, x, arr[x]);
				update(1, 0, n - 1, y, arr[y]);
			}
		}
	}
	return 0;
}