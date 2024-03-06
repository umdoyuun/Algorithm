#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v[100001];
int par[100001][18];
int depth[100001];
bool visit[100001];

void dfs(int x, int pre) {
	visit[x] = true;
	par[x][0] = pre;
	depth[x] = depth[pre] + 1;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (visit[y]) continue;
		dfs(y, x);
	}
}

int lca(int x, int y) {
	if (depth[x] > depth[y]) {
		swap(x, y);
	}
	for (int i = 17; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			y = par[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
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
	for (int y = 1; y < 18; y++) {
		for (int x = 1; x <= n; x++) {
			par[x][y] = par[par[x][y - 1]][y - 1];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
	return 0;
}