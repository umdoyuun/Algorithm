#include <iostream>
#include <vector>
using namespace std;

int n, m, res;
vector<int> v[30001];
int par[30001][16];
int level[30001];

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
	for(int k = 1; k < 16; k++){
		for (int i = 2; i <= n; i++) {
			par[i][k] = par[par[i][k - 1]][k - 1];
		}
	}
}

int lca(int x, int y) {
	int ret = 0;
	if (level[y] < level[x]) swap(x, y);
	for (int i = 15; i >= 0; i--) {
		if (level[y] - level[x] >= (1 << i)) {
			y = par[y][i];
			ret += (1 << i);
		}
	}
	if (x == y) return ret;
	for (int i = 15; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
			ret += (1 << (i + 1));
		}
	}
	return ret + 2;
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
	int x, y;
	cin >> x;
	for (int i = 1; i < m; i++) {
		cin >> y;
		res += lca(x, y);
		x = y;
	}
	cout << res;
	return 0;
}