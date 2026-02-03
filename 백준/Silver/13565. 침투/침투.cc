#include <iostream>
#include <queue>
using namespace std;

int n, m;
char coord[1001][1001];
bool visit[1001][1001];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == n - 1) return true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || coord[nx][ny] == '1') continue;
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	return false;
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
	bool res = false;
	for (int i = 0; i < m; i++) {
		if (!visit[0][i] && coord[0][i] == '0') {
			res = bfs(0, i);
			if (res) break;
		}
	}
	if (res) cout << "YES";
	else cout << "NO";
	return 0;
}