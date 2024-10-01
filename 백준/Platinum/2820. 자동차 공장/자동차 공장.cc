#include <iostream>
#include <vector>
using namespace std;

int salary[500001];
int dat[500001];
int cs[500001];
int ce[500001];


int n, m, cnt;
vector<int> v[500001];

struct node {
	int value, lazy;
};

node seg[500001 * 4];

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
	cs[x] = dat[x] + 1;
	update(1, 0, n - 1, dat[x], dat[x], salary[x]);
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
	cin >> n >> m;
	cnt = 0;
	cin >> salary[0];
	for (int i = 1; i < n; i++) {
		int x, p;
		cin >> p >> x;
		v[x - 1].push_back(i);
		salary[i] = p;
	}
	dfs(0);

	for (int i = 0; i < m; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == 'p') {
			int a, x;
			cin >> a >> x;
			if(cs[a - 1] <= ce[a - 1])
				update(1, 0, n - 1, cs[a - 1], ce[a - 1], x);
		}
		else {
			int x;
			cin >> x;
			query(1, 0, n - 1, cs[x - 1] - 1);
		}
	}
	return 0;
}