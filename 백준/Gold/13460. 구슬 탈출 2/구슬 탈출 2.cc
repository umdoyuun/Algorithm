#include <iostream>
#include <queue>
using namespace std;

struct node {
	int rx, ry, bx, by, cnt;
};

char map[10][10];
bool visit[10][10][10][10];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int srx, int sry, int sbx, int sby) {
	queue<node> q;
	q.push({ srx, sry, sbx, sby, 0 });
	visit[srx][sry][sbx][sby] = true;
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt >= 10) break;
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0;
			while (true) {
				if (map[nrx + dx[i]][nry + dy[i]] != '#' && map[nrx][nry] != 'O') {
					nrx += dx[i];
					nry += dy[i];
					rc++;
				}
				else break;
			}
			while (true) {
				if (map[nbx + dx[i]][nby + dy[i]] != '#' && map[nbx][nby] != 'O') {
					nbx += dx[i];
					nby += dy[i];
					bc++;
				}
				else break;
			}
			if (map[nbx][nby] == 'O') continue;
			if (map[nrx][nry] == 'O') return cnt + 1;
			if (nrx == nbx && nry == nby) {
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			
			if (visit[nrx][nry][nbx][nby]) continue;
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx, nry, nbx, nby, cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}
	cout << bfs(rx, ry, bx, by);
	return 0;
}