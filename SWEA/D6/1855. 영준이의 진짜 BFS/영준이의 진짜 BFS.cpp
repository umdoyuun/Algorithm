#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<int> v[100001];
int par[100001][18];
int depth[100001];
bool visit[100001];
long long result;

void init() {
	result = 0;
	for (int i = 0; i <= n; i++) {
		v[i].clear();
	}
	memset(visit, false, sizeof(visit));
	memset(depth, 0, sizeof(depth));
}

int LCA(int x, int y) {
	int cnt = 0;
	if (x == y) return 0;
	if (depth[x] > depth[y])
		swap(x, y);
	if (par[y][0] == x) {
		return 1;
	}
	for (int i = 17; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			y = par[y][i];
			cnt += (1 << i);
		}
	}
	if (par[y][0] != par[x][0]) {
		for (int i = 17; i >= 0; i--) {
			if (par[x][i] != par[y][i]) {
				cnt += 2 * (1 << i);
				x = par[x][i];
				y = par[y][i];
			}
		}
	}
	return cnt + 2;
}

void bfs() {
	int pre, cur;
	queue<int> q;
	visit[1] = true;
	q.push(1);
	cur = pre = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cur = x;
		result += LCA(pre, cur);
		pre = cur;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (visit[y]) continue;
			visit[y] = true;
			q.push(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		init();
		for (int i = 2; i <= n; i++) {
			int k;
			cin >> k;
			v[k].push_back(i);
			par[i][0] = k;
			depth[i] = depth[k] + 1;
		}
		for (int j = 1; j < 18; j++) {
			for (int i = 1; i <= n; i++) {
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}
		bfs();
		cout << '#' << tc << ' ' << result << '\n';
	}
	return 0;
}