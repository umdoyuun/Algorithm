#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long arr[1000001];

struct node {
	long long mx, mx2, cnt, sum;
};

node seg[1000001 * 4];

node merge(node a, node b) {
	if (a.mx == b.mx) {
		return { a.mx, max(a.mx2, b.mx2), a.cnt + b.cnt, a.sum + b.sum };
	}
	else if (a.mx < b.mx) {
		return { b.mx, max(b.mx2, a.mx), b.cnt, a.sum + b.sum };
	}
	else return { a.mx, max(a.mx2, b.mx), a.cnt, a.sum + b.sum };
}

void init(int x, int s, int e) {
	if (s == e) {
		seg[x].mx = arr[s];
		seg[x].sum = arr[s];
		seg[x].cnt = 1;
		seg[x].mx2 = -1;
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x] = merge(seg[x * 2], seg[x * 2 + 1]);
}

void lazy_update(int x, int s, int e) {
	if (s == e) return;
	for (int i = x * 2; i <= x * 2 + 1; i++) {
		if (seg[x].mx < seg[i].mx) {
			seg[i].sum -= seg[i].cnt * (seg[i].mx - seg[x].mx);
			seg[i].mx = seg[x].mx;
		}
	}
}

void update(int x, int s, int e, int l, int r, int diff) {
	lazy_update(x, s, e);
	if (r < s || l > e || seg[x].mx <= diff) return;
	else if (l <= s && e <= r && seg[x].mx2 < diff) {
		seg[x].sum -= seg[x].cnt * (seg[x].mx - diff);
		seg[x].mx = diff;
		lazy_update(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, l, r, diff);
	update(x * 2 + 1, mid + 1, e, l, r, diff);
	seg[x] = merge(seg[x * 2], seg[x * 2 + 1]);
}

long long getsum(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || l > e) return 0;
	else if (l <= s && e <= r) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return getsum(x * 2, s, mid, l, r) + getsum(x * 2 + 1, mid + 1, e, l, r);
}

long long getmax(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || l > e) return 0;
	else if (l <= s && e <= r) {
		return seg[x].mx;
	}
	int mid = s + (e - s) / 2;
	return max(getmax(x * 2, s, mid, l, r), getmax(x * 2 + 1, mid + 1, e, l, r));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (register int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	cin >> m;
	for (register int i = 0; i < m; i++) {
		int cmd, l, r;
		long long res, x;
		cin >> cmd >> l >> r;
		l--, r--;

		if (cmd == 1) {
			cin >> x;
			update(1, 0, n - 1, l, r, x);
		}
		else if (cmd == 2) {
			res = getmax(1, 0, n - 1, l, r);
			cout << res << '\n';
		}
		else {
			res = getsum(1, 0, n - 1, l, r);
			cout << res << '\n';
		}
	}
	return 0;
}