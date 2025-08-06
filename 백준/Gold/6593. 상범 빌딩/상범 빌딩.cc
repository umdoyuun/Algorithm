#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int k, n, m, sx, sy, sz, ex, ey, ez;
bool visit[31][31][31];
char graph[31][31][31];

struct node {
	int x, y, z, cnt;
};

int dx[6] = { 0, 0, 1, 0, -1, 0 };
int dy[6] = { 0, 0, 0, 1, 0, -1 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };

void init() {
	for (int l = 0; l < k; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[l][i][j];
				if (graph[l][i][j] == 'S') {
					sx = i;
					sy = j;
					sz = l;
				}
				else if (graph[l][i][j] == 'E') {
					ex = i;
					ey = j;
					ez = l;
				}
			}
		}
	}
	memset(visit, false, sizeof(visit));
}

int bfs() {
	queue<node> q;
	q.push({ sx, sy, sz, 0 });
	visit[sx][sy][sz] = true;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.x == ex && cur.y == ey && cur.z == ez) {
			return cur.cnt;
		}
		for (int i = 0; i < 6; i++) {
			node next = { cur.x + dx[i], cur.y + dy[i], cur.z + dz[i], cur.cnt + 1 };
			if (next.x < 0 || next.y < 0 || next.z < 0 || next.x >= n || next.y >= m || next.z >= k || visit[next.z][next.x][next.y] || graph[next.z][next.x][next.y] == '#') continue;
			visit[next.z][next.x][next.y] = true;
			q.push(next);
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> k >> n >> m;
		if (!k) break;
		init();
		int ret = bfs();
		if (ret == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << ret << " minute(s).\n";
		}
	}
	return 0;
}