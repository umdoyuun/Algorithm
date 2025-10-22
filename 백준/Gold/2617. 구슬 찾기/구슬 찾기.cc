#include <iostream>
#include <vector>
using namespace std;

int n, m, res;
vector<int> v[100][2];
bool visit[100][100];

int dfs(int x, int d, int k) {
	visit[x][k] = true;
	int cnt = 1;
	for (int y : v[x][d]) {
		if (visit[y][k]) continue;
		cnt += dfs(y, d, k);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x][0].push_back(y);
		v[y][1].push_back(x);
	}

	int tar = (n + 1) / 2;

	for (int i = 1; i <= n; i++) {
		if (dfs(i, 0, i) > tar || (dfs(i, 1, i) > tar)) {
			res++;
		}
	}
	cout << res << '\n';
	return 0;
}