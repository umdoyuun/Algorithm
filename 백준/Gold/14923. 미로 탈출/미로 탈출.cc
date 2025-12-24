#include <iostream>
#include <queue>
using namespace std;

int n, m, sx, sy, ex, ey;
int coord[1001][1001];
bool visit[1001][1001][2];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class node {
public:
	int x, y, cnt, magic;
};

int bfs() {
	queue<node> q;
	q.push({ sx, sy, 0, 0 });
	visit[sx][sy][0] = true;
	while (!q.empty()) {		
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int magic = q.front().magic;
		q.pop();
		if (x == ex && y == ey) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nm = magic;
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (coord[nx][ny] == 1) {
				if (nm == 1) continue;
				nm = 1;
			}
			if (visit[nx][ny][nm]) continue;
			visit[nx][ny][nm] = true;
			q.push({ nx, ny, cnt + 1, nm });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> coord[i][j];
		}
	}
	int ret = bfs();
	cout << ret;
	return 0;
}