#include <iostream>
#include <cstring>
using namespace std;

int n, m, cnt;
int seg[200001 * 4], arr[100001];

int seg_init(int x, int s, int e) {
	if (s == e) {		
		if (s < n) return seg[x] = 1;
		else return seg[x] = 0;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = seg_init(x * 2, s, mid) + seg_init(x * 2 + 1, mid + 1, e);
}

void init() {
	memset(seg, 0, sizeof(seg));
	seg_init(1, 0, n + m);
	for (int i = 1; i <= n; i++) {
		arr[i] = n - i;
	}
	cnt = n;
}

int update(int x, int s, int e, int idx, int value) {
	if (s > idx || idx > e) return seg[x];
	if (s == e) {
		return seg[x] = value;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, value) + update(x * 2 + 1, mid + 1, e, idx, value);
}

long long query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, x;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		init();
		for (int i = 0; i < m; i++) {
			cin >> x;
			cout << query(1, 0, n + m, arr[x] + 1, cnt) << ' ';
			update(1, 0, n + m, arr[x], 0);
			update(1, 0, n + m, cnt, 1);
			arr[x] = cnt++;
		}
		cout << '\n';
	}
	return 0;
}