#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v[50001];
int par[50001][17];
int dep[50001];

void dfs(int x, int pre) {
	par[x][0] = pre;
	dep[x] = dep[pre] + 1;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (y == pre || par[y][0] != 0) continue;
		dfs(y, x);
	}
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 16; i >= 0; i--) {
		if (dep[y] - dep[x] >= (1 << i)) {
			y = par[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 16; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			y = par[y][i];
			x = par[x][i];
		}
	}
	return par[x][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	cin >> m;
	for (int y = 1; y < 17; y++) {
		for (int x = 1; x <= n; x++) {
			par[x][y] = par[par[x][y - 1]][y - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
	return 0;
}