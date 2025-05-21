#include <iostream>
using namespace std;

int n, m;
int arr[100001];

bool seg[100001 * 4];

bool check(int x) {
	return arr[x] > arr[x - 1];
}

void init(int x, int s, int e) {
	if (s == e) {
		seg[x] = check(s);
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x] = seg[x * 2] && seg[x * 2 + 1];
}

void update(int x, int s, int e, int idx) {
	if (idx < s || e < idx) return;
	if (s == e) {
		seg[x] = check(s);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, idx);
	update(x * 2 + 1, mid + 1, e, idx);
	seg[x] = seg[x * 2] && seg[x * 2 + 1];
}

bool query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return true;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) && query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			if (query(1, 1, n, x + 1, y)) {
				cout << "CS204\n";
			}
			else {
				cout << "HSS090\n";
			}
		}
		else {
			swap(arr[x], arr[y]);
			if (x > 1) update(1, 1, n, x);
			if (x < n) update(1, 1, n, x + 1);
			if (y > 1) update(1, 1, n, y);
			if (y < n) update(1, 1, n, y + 1);
		}
	}
	return 0;
}