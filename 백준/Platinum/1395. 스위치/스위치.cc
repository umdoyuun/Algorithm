#include <iostream>
using namespace std;

struct node {
	int sum, lazy;
};
node seg[100001 * 4];

void lazy(int x, int s, int e) {
	if (seg[x].lazy) {
		seg[x].sum = (e - s + 1) - seg[x].sum;
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				seg[i].lazy ^= 1;
			}
		}
		seg[x].lazy = 0;
	}
}

void update(int x, int s, int e, int l, int r) {
	lazy(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		seg[x].lazy ^= 1;
		lazy(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, l, r);
	update(x * 2 + 1, mid + 1, e, l, r);
	seg[x].sum = seg[x * 2].sum + seg[x * 2 + 1].sum;
}

int get_sum(int x, int s, int e, int l, int r) {
	lazy(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return get_sum(x * 2, s, mid, l, r) + get_sum(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cmd, l, r;
		cin >> cmd >> l >> r;
		l--, r--;
		if (cmd == 0) {
			update(1, 0, n - 1, l, r);
		}
		else {
			cout << get_sum(1, 0, n - 1, l, r) << '\n';
		}
	}
	return 0;
}