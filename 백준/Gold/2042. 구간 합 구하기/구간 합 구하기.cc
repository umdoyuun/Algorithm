#include <iostream>
using namespace std;

int n, m, k;
long long arr[1000001];
long long seg[1000001 * 4];

long long init(int x, int s, int e) {
	if (s == e) return seg[x] = arr[s];
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

long long update(int x, int s, int e, int idx, long long diff) {
	if (idx > e || idx < s) return seg[x];
	if (s == e) {
		return seg[x] = diff;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, diff) + update(x * 2 + 1, mid + 1, e, idx, diff);
}

long long query(int x, int s, int e, int left, int right){
	if (left > e || right < s) return 0;
	if (left <= s && e <= right) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, left, right) + query(x * 2 + 1, mid + 1, e, left, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (register int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	for (register int i = 0; i < m + k; i++) {
		int cmd, x;
		cin >> cmd >> x;
		if (cmd == 1) {
			long long y;
			cin >> y;
			update(1, 0, n - 1, x - 1, y);
		}
		else {
			int y;
			cin >> y;
			cout << query(1, 0, n - 1, x - 1, y - 1) << '\n';
		}
	}
	return 0;
}