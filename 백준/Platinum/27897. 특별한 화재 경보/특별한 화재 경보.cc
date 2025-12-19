#include <iostream>
#include <algorithm>
using namespace std;

long long n, l, res;

int seg[500001 * 4];

void update(int node, int s, int e, int idx) {
	if (s == e) ++seg[node];
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}

int query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		res += query(1, 1, n, x, n);
		update(1, 1, n, x);
	}
	res = min(res + l, n * (n - 1) / 2);
	cout << res << '\n';
	return 0;
}