#include <iostream>
using namespace std;

int n, m, sx, sy, res;
char graph[605][605];
bool visit[605][605];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y) {
	visit[x][y] = true;
	if (graph[x][y] == 'P') res++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'I') {
				sx = i;
				sy = j;
			}
			else if (graph[i][j] == 'X') {
				visit[i][j] = true;
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		visit[0][i] = true;
		visit[n + 1][i] = true;
	}
	for (int i = 0; i <= n; i++) {
		visit[i][0] = true;
		visit[i][m + 1] = true;
	}
	dfs(sx, sy);
	if (res) {
		cout << res << '\n';
	}
	else {
		cout << "TT\n";
	}
	return 0;
}