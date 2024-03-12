#include <iostream>
using namespace std;

int n, m;
int arr[500001];
int seg[500001 * 4];
int lazy[500001 * 4];

int init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = arr[s];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) ^ init(x * 2 + 1, mid + 1, e);
}

void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		if ((e - s + 1) % 2 == 1) {
			seg[x] = seg[x] ^ lazy[x];
		}
		if (s != e) {			
			lazy[x * 2] ^= lazy[x];
			lazy[x * 2 + 1] ^= lazy[x];
		}
		lazy[x] = 0;
	}
}

void update_range(int x, int s, int e, int l, int r, int diff) {
	update_lazy(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[x] ^= diff;
		update_lazy(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update_range(x * 2, s, mid, l, r, diff);
	update_range(x * 2 + 1, mid + 1, e, l, r, diff);
	seg[x] = seg[x * 2] ^ seg[x * 2 + 1];
}

int get_xor(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return get_xor(x * 2, s, mid, l, r) ^ get_xor(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, x, y, k;
		cin >> cmd >> x >> y;
		switch (cmd) {
		case 1:
			cin >> k;
			update_range(1, 0, n - 1, x, y, k);
			break;
		case 2:
			cout << get_xor(1, 0, n - 1, x, y) << '\n';
		}
	}
	return 0;
}