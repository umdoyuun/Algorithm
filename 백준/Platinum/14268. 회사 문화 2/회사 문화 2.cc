#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt;
vector<int> v[100001];
int dat[100001];
int cs[100001];
int ce[100001];

struct node {
	long long value, lazy;
};

node seg[100001 * 4];

void lazy(int x, int s, int e) {
	if (seg[x].lazy) {
		if (s != e) {
			seg[x * 2].lazy += seg[x].lazy;
			seg[x * 2 + 1].lazy += seg[x].lazy;
		}
		else {
			seg[x].value += seg[x].lazy;
		}
		seg[x].lazy = 0;
	}
}

void update(int x, int s, int e, int l, int r, long long v) {
	lazy(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		seg[x].lazy = v;
		lazy(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, l, r, v);
	update(x * 2 + 1, mid + 1, e, l, r, v);
}

void query(int x, int s, int e, int idx) {
	lazy(x, s, e);
	if (idx < s || idx > e) return;
	if (s == e) {
		cout << seg[x].value << '\n';
		return;
	}
	int mid = s + (e - s) / 2;
	query(x * 2, s, mid, idx);
	query(x * 2 + 1, mid + 1, e, idx);
}

void dfs(int x) {
	cs[x] = dat[x];
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		dat[y] = ++cnt;
		dfs(y);
	}
	ce[x] = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != -1) {
			v[x - 1].push_back(i);
		}
	}
	dfs(0);

	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int x;
			long long v;
			cin >> x >> v;
			update(1, 0, n - 1, cs[x - 1], ce[x - 1], v);
		}
		else {
			int x;
			cin >> x;
			query(1, 0, n - 1, cs[x - 1]);
		}
	}
	return 0;
}