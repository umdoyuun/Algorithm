#include <iostream>
#include <vector>
using namespace std;

int n, k;
int res_min, res_max;
int mx;
vector<pair<int, int>> v[100001];
bool visit[100001];
int par[100001][18];
int dist[100001][18][2];
int depth[100001];

void dfs(int x, int pre) {
	visit[x] = true;
	par[x][0] = pre;
	depth[x] = depth[pre] + 1;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i].first;
		if (visit[y]) continue;
		dist[y][0][0] = v[x][i].second;
		dist[y][0][1] = v[x][i].second;
		dfs(y, x);
	}
}

void lca(int x, int y) {
	if (depth[x] > depth[y])
		swap(x, y);
	for (int i = mx; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			for (int j = 0; j <= i; j++) {
				res_max = max(res_max, dist[y][j][0]);
				res_min = min(res_min, dist[y][j][1]);
			}
			y = par[y][i];
		}
	}

	if (y == x) {
		return;
	}

	for (int i = mx; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			for (int j = 0; j <= i; j++) {
				res_max = max(res_max, dist[x][j][0]);
				res_max = max(res_max, dist[y][j][0]);
				res_min = min(res_min, dist[x][j][1]);
				res_min = min(res_min, dist[y][j][1]);
			}
			x = par[x][i];
			y = par[y][i];
		}
	}
	if (x == y) return;
	res_max = max(res_max, dist[x][0][0]);
	res_max = max(res_max, dist[y][0][0]);
	res_min = min(res_min, dist[x][0][1]);
	res_min = min(res_min, dist[y][0][1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ y, c });
		v[y].push_back({ x, c });
	}
	dfs(1, 0);
	for (int y = 1; y < 18; y++) {
		if (n < (1 << y)) {
			mx = y - 1;
			break;
		}
		for (int x = 1; x <= n; x++) {
			par[x][y] = par[par[x][y - 1]][y - 1];
			dist[x][y][0] = max(dist[par[x][y - 1]][y - 1][0], dist[x][y - 1][0]);
			dist[x][y][1] = min(dist[par[x][y - 1]][y - 1][1], dist[x][y - 1][1]);
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		res_min = 0x7fffffff;
		res_max = 0;
		int x, y;
		cin >> x >> y;
		lca(x, y);
		cout << res_min << ' ' << res_max << '\n';
	}
	return 0;
}