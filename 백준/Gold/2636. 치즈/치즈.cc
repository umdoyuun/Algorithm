#include <iostream>
#include <cstring>
using namespace std;

int n, m, last_cnt, cnt, res;
int graph[101][101];
bool visit[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y) {
	visit[x][y] = true;
	if (graph[x][y]) {
		graph[x][y] = 0;
		cnt--;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny]) continue;
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
			if (graph[i][j]) cnt++;
		}
	}
	last_cnt = cnt;
	while (cnt) {
		last_cnt = cnt;
		memset(visit, false, sizeof(visit));
		dfs(0, 0);
		res++;
	}
	cout << res << '\n' << last_cnt << '\n';
	return 0;
}