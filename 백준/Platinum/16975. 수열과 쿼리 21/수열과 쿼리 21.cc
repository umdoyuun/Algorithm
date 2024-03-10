#include <iostream>
using namespace std;

int n, m;
int arr[100001];
long long seg[100001 * 4];
long long lazy[100001 * 4];

long long init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = arr[s];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		seg[x] += (e - s + 1) * lazy[x];
		if (s != e) {
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}

long long update_range(int x, int s, int e, int l, int r, int diff) {
	update_lazy(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		seg[x] += (e - s + 1) * diff;
		if (s != e) {
			lazy[x * 2] += diff;
			lazy[x * 2 + 1] += diff;
		}
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update_range(x * 2, s, mid, l, r, diff) + update_range(x * 2 + 1, mid + 1, e, l, r, diff);
}

long long get(int x, int s, int e, int idx) {
	update_lazy(x, s, e);
	if (idx > e || idx < s) return 0;
	if (s == e) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return get(x * 2, s, mid, idx) + get(x * 2 + 1, mid + 1, e, idx);
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
		int cmd, x, y, diff;
		cin >> cmd;
		switch (cmd) {
		case 1:
			cin >> x >> y >> diff;
			update_range(1, 0, n - 1, x - 1, y - 1, diff);
			break;
		case 2:
			cin >> x;
			cout << get(1, 0, n - 1, x - 1) << '\n';
			break;
		}
	}
	return 0;
}