#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	long long sum, mn;
};

int n, m;
int arr[200001];
long long lazy[200001 * 4];
node seg[200001 * 4];

node init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = { arr[s], arr[s] };
	}
	int mid = s + (e - s) / 2;
	node a = init(x * 2, s, mid);
	node b = init(x * 2 + 1, mid + 1, e);
	return seg[x] = { a.sum + b.sum, min(a.mn, b.mn) };
}

void lazy_update(int x, int s, int e) {
	if (lazy[x]) {
		seg[x].mn += lazy[x];
		seg[x].sum += lazy[x] * (e - s + 1);
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				lazy[i] += lazy[x];
			}
		}
		lazy[x] = 0;
	}
}

node update(int x, int s, int e, int l, int r, long long v) {
	lazy_update(x, s, e);
	if (r < s || e < l) return seg[x];
	if (l <= s && e <= r) {
		lazy[x] += v;
		lazy_update(x, s, e);
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	node a = update(x * 2, s, mid, l, r, v);
	node b = update(x * 2 + 1, mid + 1, e, l, r, v);
	return seg[x] = { a.sum + b.sum, min(a.mn, b.mn) };
}

long long sum_query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return sum_query(x * 2, s, mid, l, r) + sum_query(x * 2 + 1, mid + 1, e, l, r);
}

long long min_query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || e < l) return 1e9;
	if (l <= s && e <= r) {
		return seg[x].mn;
	}
	int mid = s + (e - s) / 2;
	return min(min_query(x * 2, s, mid, l, r), min_query(x * 2 + 1, mid + 1, e, l, r));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (register int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	for (register int i = 0; i < m; i++) {
		char cmd;
		int a, b;
		long long c;
		cin >> cmd >> a >> b;
		a--;b--;
		if (cmd == 'M') {
			cout << min_query(1, 0, n - 1, a, b) << '\n';
		}
		else if (cmd == 'S') {
			cout << sum_query(1, 0, n - 1, a, b) << '\n';
		}
		else {
			cin >> c;
			update(1, 0, n - 1, a, b, c);
		}
	}
	return 0;
}