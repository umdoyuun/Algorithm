#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int x, y, cnt;
	bool operator < (const node& other) const {
		return cnt > other.cnt;
	}
};

int n, m;
char coord[301][301];
bool visit[301][301];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int sx, int sy, int ex, int ey) {
	priority_queue<node> pq;
	pq.push({ sx, sy, 0 });
	visit[sx][sy] = true;
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cnt = pq.top().cnt;
		if (x == ex && y == ey) return cnt;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			int ncnt = cnt;
			if (coord[nx][ny] != '0') ncnt++;
			pq.push({ nx, ny, ncnt});
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sx, sy, ex, ey;
	cin >> n >> m >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> coord[i][j];
		}
	}
	int res = bfs(sx, sy, ex, ey);
	cout << res << '\n';
	return 0;
}