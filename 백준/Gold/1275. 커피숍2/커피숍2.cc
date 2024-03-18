#include <iostream>
using namespace std;

int n, m;
int arr[100001];
long long seg[100001 * 4];

long long init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = arr[s];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

long long update(int x, int s, int e, int idx, int val) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) {
		return seg[x] = val;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, val) + update(x * 2 + 1, mid + 1, e, idx, val);
}

long long get_sum(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return get_sum(x * 2, s, mid, l, r) + get_sum(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << get_sum(1, 0, n - 1, x - 1, y - 1) << '\n';
		update(1, 0, n - 1, a - 1, b);
	}
	return 0;
}