#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<int, int> m;
int seg[200001 * 4];
int lazy[200001 * 4];
pair<int, int> arr[100001];

void lazy_update(int x, int s, int e) {
	if (lazy[x]) {
		seg[x] = max(seg[x], lazy[x]);
		if (s != e) {
			lazy[x * 2] = max(lazy[x * 2], seg[x]);
			lazy[x * 2 + 1] = max(lazy[x * 2 + 1], seg[x]);
		}
		lazy[x] = 0;
	}
}

int update(int x, int s, int e, int l, int r, int v) {
	lazy_update(x, s, e);
	if (l > e || s > r) return seg[x];
	if (l <= s && e <= r) {
		lazy[x] = v;
		lazy_update(x, s, e);
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = max(update(x * 2, s, mid, l, r, v), update(x * 2 + 1, mid + 1, e, l, r, v));
}

//void print(int x, int s, int e) {
//	lazy_update(x, s, e);
//	if (s == e) {
//		cout << seg[x] << ' ';
//		return;
//	}
//	int mid = s + (e - s) / 2;
//	print(x * 2, s, mid);
//	print(x * 2 + 1, mid + 1, e);
//}

int query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return max(query(x * 2, s, mid, l, r), query(x * 2 + 1, mid + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
		arr[i].second += arr[i].first;
		m[arr[i].first] = 0;
		m[arr[i].second - 1] = 0;
	}
	int cnt = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		it->second = cnt++;
	}
	for (int i = 0; i < n; i++) {
		int v = query(1, 0, cnt - 1, m[arr[i].first], m[arr[i].second - 1]) + 1;
		update(1, 0, cnt - 1, m[arr[i].first], m[arr[i].second - 1], v);
	}
	cout << seg[1] << '\n';
	return 0;
}