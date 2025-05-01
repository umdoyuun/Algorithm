#include <iostream>
using namespace std;

int n, m;
long long arr[300001];
pair<long long, long long> seg[300000 * 4];

void init(int x, int s, int e) {
	if (s == e) {
		if (s % 2) {
			seg[x].second = arr[s];
		}
		else {
			seg[x].first = arr[s];
		}
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);

	seg[x] = { seg[x * 2].first + seg[x * 2 + 1].first, seg[x * 2].second + seg[x * 2 + 1].second };
}

void update(int x, int s, int e, int idx, long long value) {
	if (e < idx || s > idx) return;
	if (s == e) {
		if (idx % 2) {
			seg[x] = { 0, value };
		}
		else {
			seg[x] = { value, 0 };
		}
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, idx, value);
	update(x * 2 + 1, mid + 1, e, idx, value);
	seg[x] = { seg[x * 2].first + seg[x * 2 + 1].first, seg[x * 2].second + seg[x * 2 + 1].second };
}

pair<long long, long long>  query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return { 0, 0 };
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	pair<long long, long long> a = query(x * 2, s, mid, l, r);
	pair<long long, long long> b = query(x * 2 + 1, mid + 1, e, l, r);
	return { a.first + b.first, a.second + b.second };
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
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			x--;y--;
			pair<long long, long long>  ret = query(1, 0, n - 1, x, y);
			long long res = ret.first - ret.second;
			if (res < 0) res *= -1;
			cout << res << '\n';
		}
		else {
			x--;
			arr[x] += y;
			update(1, 0, n - 1, x, arr[x]);
		}
	}
	return 0;
}