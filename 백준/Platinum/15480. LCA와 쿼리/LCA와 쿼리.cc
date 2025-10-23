#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v[100001];
int level[100001];
int parent[100001][18];

void dfs(int x, int pre) {
	for (int y : v[x]) {
		if (y == pre) continue;
		level[y] = level[x] + 1;
		parent[y][0] = x;
		dfs(y, x);
	}
}

void init() {
	level[1] = 1;
	dfs(1, 0);
	for (int k = 1; k < 18; k++) {
		for (int i = 1; i <= n; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}
}

int lca(int x, int y) {
	if (level[x] > level[y]) swap(x, y);
	for (int i = 17; i >= 0; i--) {
		if (level[y] - level[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}

int check(int a, int b, int c) {
	int ret = level[a] > level[b] ? a : b;
	ret = level[ret] > level[c] ? ret : c;
	return ret;
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
	cin >> m;
	for (int i = 0; i < m; i++) {
		int r, x, y;
		cin >> r >> x >> y;
		int a = lca(r, x);
		int b = lca(r, y);
		int c = lca(x, y);
		int res = check(a, b, c);
		cout << res << '\n';
	}

	return 0;
}