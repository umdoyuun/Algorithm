#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt;
bool visit[101][101];
vector<int> v[101][2];	//0: up  / 1: down

void dfs(int k, int x, int d) {
	visit[k][x] = true;
	cnt--;
	for (int y : v[x][d]) {
		if (visit[k][y]) continue;
		dfs(k, y, d);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x][1].push_back(y);
		v[y][0].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		cnt = n + 1;
		dfs(i, i, 0);
		dfs(i, i, 1);
		cout << cnt << '\n';
	}
	return 0;
}