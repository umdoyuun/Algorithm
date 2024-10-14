#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, cnt;
int s_dat[100001];
int e_dat[100001];
int seg[100001 * 4];
int lazy[100001 * 4];
vector<int> v[100001];

void dfs(int x) {
	s_dat[x] = cnt++;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		dfs(y);
	}
	e_dat[x] = cnt - 1;
}

void lazy_update(int x, int s, int e) {
	if (lazy[x] != -1) {
		seg[x] = (e - s + 1) * lazy[x];
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				lazy[i] = lazy[x];
			}
		}
		lazy[x] = -1;
	}
}

void update(int x, int s, int e, int l, int r, int v) {
	lazy_update(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[x] = v;
		lazy_update(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, l, r, v);
	update(x * 2 + 1, mid + 1, e, l, r, v);
	seg[x] = seg[x * 2] + seg[x * 2 + 1];
	return;
}

int query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
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
	cin >> n;
	int par;
	cin >> par;
	for (int i = 1; i < n; i++) {
		cin >> par;
		v[par - 1].push_back(i);
	}
	dfs(0);
	memset(lazy, -1, sizeof(lazy));
	update(1, 0, n - 1, s_dat[0], e_dat[0], 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, x;
		cin >> cmd >> x;
		x--;
		if (cmd == 1) {
			update(1, 0, n - 1, s_dat[x] + 1, e_dat[x], 1);
		}
		else if (cmd == 2) {
			update(1, 0, n - 1, s_dat[x] + 1, e_dat[x], 0);
		}
		else {
			cout << query(1, 0, n - 1, s_dat[x] + 1, e_dat[x]) << '\n';
		}
	}
	return 0;
}