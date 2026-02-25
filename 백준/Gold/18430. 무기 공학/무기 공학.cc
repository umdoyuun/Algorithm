#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res, cnt;
int coord[6][6];
int visit[6][6];

int dx[4][2] = {
	{1, 0},
	{-1, 0},
	{-1, 0},
	{1, 0}
};

int dy[4][2] = {
	{0, -1},
	{0, -1},
	{0, 1},
	{0, 1}
};

void dfs(int x, int y, int sum) {
	res = max(res, sum);
	if (x >= n || y >= m) return;
	int nx, ny, npx = x, npy = y + 1;
	if (npy == m) {
		npx = x + 1;
		npy = 0;
	}
	if (visit[x][y]) {
		dfs(npx, npy, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		bool flag = true;
		int nsum = coord[x][y] * 2;
		for (int j = 0; j < 2; j++) {
			nx = x + dx[i][j];
			ny = y + dy[i][j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny]) {
				flag = false;
				continue;
			}
			nsum += coord[nx][ny];
		}
		if (flag) {
			visit[x][y] = ++cnt;
			for (int j = 0; j < 2; j++) {
				nx = x + dx[i][j];
				ny = y + dy[i][j];
				visit[nx][ny] = cnt;				
			}
			dfs(npx, npy, sum + nsum);
			cnt--;
			visit[x][y] = 0;
			for (int j = 0; j < 2; j++) {
				nx = x + dx[i][j];
				ny = y + dy[i][j];
				visit[nx][ny] = 0;
			}
		}
	}
	dfs(npx, npy, sum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> coord[i][j];
		}
	}
	dfs(0, 0, 0);
	cout << res << '\n';
	return 0;
}