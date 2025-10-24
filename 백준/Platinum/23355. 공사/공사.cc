#include <iostream>
#include <vector>
using namespace std;

const int mx = 250001;
int n, q;
vector<int> v[mx];
int par[mx][19];
int level[mx];

void dfs(int x, int pre) {
	for (int y : v[x]) {
		if (y == pre) continue;
		level[y] = level[x] + 1;
		par[y][0] = x;
		dfs(y, x);
	}
}

void init() {
	level[1] = 1;
	dfs(1, 0);
	for (int k = 1; k < 19; k++) {
		for (int i = 1; i <= n; i++) {
			par[i][k] = par[par[i][k - 1]][k - 1];
		}
	}
}

int lca(int x, int y) {
	if (level[x] > level[y]) swap(x, y);
	for (int i = 18; i >= 0; i--) {
		if (level[y] - level[x] >= (1 << i)) {
			y = par[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 18; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

bool check(int a, int b, int c, int tar) {
	int ret = level[a] > level[b] ? a : b;
	ret = level[ret] > level[c] ? ret : c;
	if (ret == tar) return false;
	else return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init();
	cin >> q;
	for (int i = 0; i < q; i++) {
		int cmd, x, y, l, r;
		cin >> cmd;
		if (cmd == 1) {
			cin >> x >> y >> l;
			int a = lca(x, y);
			int b = lca(x, l);
			int c = lca(y, l);
			if (check(a, b, c, l)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			cin >> x >> y >> l >> r;

			if (x == y) {
				cout << "YES\n";
				continue;
			}

			int a = lca(x, y);

			int b1 = lca(x, l);
			int c1 = lca(y, l);
			bool l_on_path = !check(a, b1, c1, l);

			int b2 = lca(x, r);
			int c2 = lca(y, r);
			bool r_on_path = !check(a, b2, c2, r);

			if (l_on_path && r_on_path) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
	}
	return 0;
}