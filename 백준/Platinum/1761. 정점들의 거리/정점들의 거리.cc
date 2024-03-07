#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> v[40001];
int par[40001][17];
int dist[40001][17];
int dep[40001];

void dfs(int x, int pre) {
	par[x][0] = pre;
	dep[x] = dep[pre] + 1;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i].first;
		int c = v[x][i].second;
		if (y == pre || par[y][0] != 0) continue;
		dist[y][0] = c;
		dfs(y, x);
	}
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	int res = 0;

	for (int i = 16; i >= 0; i--) {
		if (dep[y] - dep[x] >= (1 << i)) {
			res += dist[y][i];
			y = par[y][i];
		}
	}
	if (x == y) return res;
	for (int i = 16; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			res += dist[x][i];
			res += dist[y][i];
			x = par[x][i];
			y = par[y][i];
		}
	}
	res += dist[x][0];
	res += dist[y][0];
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ y,c });
		v[y].push_back({ x,c });
	}
	dfs(1, 0);
	cin >> m;
	for (int y = 1; y < 17; y++) {
		for (int x = 1; x <= n; x++) {
			par[x][y] = par[par[x][y - 1]][y - 1];
			dist[x][y] = dist[x][y - 1] + dist[par[x][y - 1]][y - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
	return 0;
}