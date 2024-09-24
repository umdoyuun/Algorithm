#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int seg[100001 * 4][2];

int init(int x, int s, int e, int t){
	if (s == e) {
		if (arr[s] % 2 == t) {
			return seg[x][t] = 1;
		}
		else return 0;
	}
	int mid = s + (e - s) / 2;
	return seg[x][t] = init(x * 2, s, mid, t) + init(x * 2 + 1, mid + 1, e, t);
}

int update(int x, int s, int e, int idx, int t) {
	if (idx > e || idx < s) return seg[x][t];
	if (s == e) {
		if (t == arr[s] % 2)
			return seg[x][t] = 1;
		else return seg[x][t] = 0;
	}
	int mid = s + (e - s) / 2;
	return seg[x][t] = update(x * 2, s, mid, idx, t) + update(x * 2 + 1, mid + 1, e, idx, t);
}

int query(int x, int s, int e, int left, int right, int t) {
	if (right < s || e < left) return 0;
	if (left <= s && e <= right) return seg[x][t];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, left, right, t) + query(x * 2 + 1, mid + 1, e, left, right, t);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (register int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	init(1, 0, n - 1, 0);
	init(1, 0, n - 1, 1);
	for (register int i = 0; i < m; i++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			if (arr[x - 1] % 2 != y % 2) {
				arr[x - 1] = y;
				update(1, 0, n - 1, x - 1, 0);
				update(1, 0, n - 1, x - 1, 1);
			}
		}
		else {
			int res = query(1, 0, n - 1, x - 1, y - 1, cmd % 2);
			cout << res << '\n';
		}
	}

	return 0;
}