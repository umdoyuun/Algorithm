#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


long long arr[100001];
struct node {
	long long sum, mx, mn;
};
node seg[100002 * 4];
long long lazy[100002 * 4][2]; // 0: sum 1: sqrt

void init(int x, int s, int e) {
	if (s == e) {
		seg[x] = { arr[s], arr[s], arr[s] };
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum, max(seg[x * 2].mx, seg[x * 2 + 1].mx), min(seg[x * 2].mn, seg[x * 2 + 1].mn) };
	return;
}

void lazy_update(int x, int s, int e) {
	if (!lazy[x][0] && !lazy[x][1]) return;
	if (!lazy[x][1]) {
		seg[x].sum += lazy[x][0] * (e - s + 1);
		seg[x].mn += lazy[x][0];
		seg[x].mx += lazy[x][0];
		if (s != e) {
			lazy[x * 2][0] += lazy[x][0];
			lazy[x * 2 + 1][0] += lazy[x][0];
		}
		lazy[x][0] = 0;
	}
	else {
		seg[x].sum = (lazy[x][1] + lazy[x][0]) * (e - s + 1);
		seg[x].mn = lazy[x][1] + lazy[x][0];
		seg[x].mx = lazy[x][1] + lazy[x][0];
		if (s != e) {
			lazy[x * 2][0] = lazy[x][0];
			lazy[x * 2][1] = lazy[x][1];
			lazy[x * 2 + 1][0] = lazy[x][0];
			lazy[x * 2 + 1][1] = lazy[x][1];
		}
		lazy[x][1] = 0;
		lazy[x][0] = 0;
	}
	return;
}

void update_sum(int x, int s, int e, int l, int r, long long diff) {
	lazy_update(x, s, e);
	if (r < s || l > e) return;
	if (l <= s && e <= r) {
		lazy[x][0] = diff;
		lazy_update(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update_sum(x * 2, s, mid, l, r, diff);
	update_sum(x * 2 + 1, mid + 1, e, l, r, diff);
	seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum, max(seg[x * 2].mx, seg[x * 2 + 1].mx), min(seg[x * 2].mn, seg[x * 2 + 1].mn) };
	return;
}

void update_sqrt(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || l > e) return;
	if (l <= s && e <= r) {
		if (floor(sqrt(seg[x].mx)) == floor(sqrt(seg[x].mn))) {
			lazy[x][1] = floor(sqrt(seg[x].mx));
			lazy_update(x, s, e);
			return;
		}
		if (seg[x].mn + 1 == seg[x].mx) {
			lazy[x][0] = sqrt(seg[x].mx) - seg[x].mx;
			lazy_update(x, s, e);
			return;
		}
	}
	int mid = s + (e - s) / 2;
	update_sqrt(x * 2, s, mid, l, r);
	update_sqrt(x * 2 + 1, mid + 1, e, l, r);
	seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum, max(seg[x * 2].mx, seg[x * 2 + 1].mx), min(seg[x * 2].mn, seg[x * 2 + 1].mn) };
	return;
}

long long query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (register int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	for (register int i = 0; i < m; i++) {
		int cmd, l, r, x;
		cin >> cmd >> l >> r;
		l--, r--;
		if (cmd == 1) {
			cin >> x;
			update_sum(1, 0, n - 1, l, r, x);
		}
		else if (cmd == 2) {
			update_sqrt(1, 0, n - 1, l, r);
		}
		else {
			long long res = query(1, 0, n - 1, l, r);
			cout << res << '\n';
		}
	}
	return 0;
}