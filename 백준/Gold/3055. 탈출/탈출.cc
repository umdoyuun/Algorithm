#include <iostream>
#include <queue>
using namespace std;

int n, m;
class node {
public:
	bool beaver;
	int x, y;
};

char coord[51][51];
int visit[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs() {
	queue<node> q;
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (coord[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (coord[i][j] == '*') {
				q.push({ false, i, j });
				visit[i][j] = 1;
			}
		}
	}
	q.push({ true, sx, sy });
	visit[sx][sy] = 1;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || coord[nx][ny] == 'X') continue;
			if (cur.beaver && coord[nx][ny] == 'D') {
				return visit[cur.x][cur.y];
			}
			if (coord[nx][ny] == 'D') continue;
			q.push({ cur.beaver, nx, ny });
			visit[nx][ny] = visit[cur.x][cur.y] + 1;
		}
	}
	return -1;
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
	int res = bfs();
	if (res == -1) {
		cout << "KAKTUS\n";
	}
	else {
		cout << res << '\n';
	}
	return 0;
}