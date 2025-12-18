#include <iostream>
#include <algorithm>
using namespace std;

const int mx = 1e9;

int n, res;
int arr[100001];
pair<int, int> seg[100000 * 4];

void init(int x, int s, int e) {
	if (s == e) {
		seg[x] = { arr[s], s };
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	if (seg[x * 2] < seg[x * 2 + 1]) {
		seg[x] = seg[x * 2];
	}
	else {
		seg[x] = seg[x * 2 + 1];
	}
}

pair<int, int> query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return{ mx, -1 };
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	pair<int, int> left = query(x * 2, s, mid, l, r);
	pair<int, int> right = query(x * 2 + 1, mid + 1, e, l, r);
	if (left.first < right.first) {
		return left;
	}
	else {
		return right;
	}
}

void find_max(int s, int e) {
	if (s < 0 || e >= n || s > e) return;
	if (s == e) {
		res = max(res, arr[s]);
		return;
	}
	pair<int, int> ret = query(1, 0, n - 1, s, e);
	res = max(res, ret.first * (e - s + 1));
	find_max(ret.second + 1, e);
	find_max(s, ret.second - 1);
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
	find_max(0, n - 1);
	cout << res << '\n';
	return 0;
}