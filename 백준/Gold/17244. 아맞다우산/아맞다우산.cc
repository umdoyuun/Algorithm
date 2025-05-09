#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[51][51];
bool visit[51][51][33];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

struct node {
	int x, y, cnt, stuffs;
};

int bfs(int sx, int sy, int ex, int ey, int key) {
	queue<node> q;
	q.push({ sx, sy, 0, 0 });
	visit[sx][sy][0] = true;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.x == ex && cur.y == ey && cur.stuffs == key) {
			return cur.cnt;
		}
		for (int i = 0; i < 4; i++) {
			node next = { cur.x + dx[i], cur.y + dy[i], cur.cnt + 1,cur.stuffs };
			if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;
			if (map[next.x][next.y] > 0) {
				next.stuffs |= (1 << map[next.x][next.y] - 1);
			}
			if (map[next.x][next.y] == -1 || visit[next.x][next.y][next.stuffs]) continue;
			q.push(next);
			visit[next.x][next.y][next.stuffs] = true;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	int sx, sy, ex, ey, cnt = 0, key = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '#') map[i][j] = -1;
			else if (c == 'S') {
				sx = i;
				sy = j;
			}
			else if (c == 'E') {
				ex = i;
				ey = j;
			}
			else if (c == 'X') {
				key |= (1 << cnt);
				map[i][j] = ++cnt;
			}			
		}
	}
	int ret = bfs(sx, sy, ex, ey, key);
	cout << ret << '\n';
	return 0;
}