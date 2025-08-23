#include <iostream>
using namespace std;

int n, m, sx, sy, res;
char graph[601][601];
bool visit[601][601];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y) {
	visit[x][y] = true;
	if (graph[x][y] == 'P') res++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] || graph[nx][ny] == 'X') continue;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'I') {
				sx = i;
				sy = j;
			}
		}
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