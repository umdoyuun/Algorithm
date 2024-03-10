#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];
pair<int, int> seg[100001 * 4];
int res;

pair<int, int> init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = { arr[s], s };
	}
	int mid = s + (e - s) / 2;
	return seg[x] = min(init(x * 2, s, mid), init(x * 2 + 1, mid + 1, e));
}

pair<int, int> update(int x, int s, int e, int idx, int diff) {
	if (idx < s || idx > e) return seg[x];
	if (s == e) {
		return seg[x] = { diff, s };
	}
	int mid = s + (e - s) / 2;
	return seg[x] = min(update(x * 2, s, mid, idx, diff), update(x * 2 + 1, mid + 1, e, idx, diff));
}

pair<int, int> get_min(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return { 1e9, 1e9 };
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return min(get_min(x * 2, s, mid, l, r), get_min(x * 2 + 1, mid + 1, e, l, r));
}

void print() {
	for (int i = 1; i <= n; i++) {
		cout << get_min(1, 1, n, i, i).first << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		switch (cmd) {
		case 1:
			update(1, 1, n, x, y);
			//print();
			break;
		case 2:
			//print();
			cout << get_min(1, 1, n, x, y).second << '\n';
		}
	}
	return 0;
}