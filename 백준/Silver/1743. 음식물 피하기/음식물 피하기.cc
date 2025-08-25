#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, res, sum;
int graph[101][101];
bool visit[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y) {
	sum++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] || !graph[nx][ny]) continue;
		visit[nx][ny] = true;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		graph[x][y] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] && !visit[i][j]) {
				sum = 0;
				visit[i][j] = true;
				dfs(i, j);
				res = max(sum, res);
			}
		}
	}
	cout << res << '\n';
	return 0;
}