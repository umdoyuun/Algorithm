#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char map[100][100];
int visit[100][100][4];

struct node {
	int x, y, cnt, dir;
	bool operator<(node right) const{
		return cnt > right.cnt;
	}
};

int g[100][100];

int bfs(int sx, int sy) {
	priority_queue<node> pq;
	pq.push({ sx, sy, -1, 4});
	
	for (int i = 0; i < 4; i++) {
		visit[sx][sy][i] = -1;
	}
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cnt = pq.top().cnt;
		int dir = pq.top().dir;
		pq.pop();
		g[x][y] = cnt;
		if (map[x][y] == 'C' && cnt >= 0) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncnt = cnt;

			if (dir != i) ncnt++;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny][i] <= ncnt || map[nx][ny] == '*') continue;
			visit[nx][ny][i] = ncnt;
			pq.push({ nx, ny, ncnt, i });
		}
	}
}

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << g[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	int sx = -1, sy = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C' && sx == -1) {
				sx = i;
				sy = j;
			}
			for(int k = 0; k < 4; k++)
				visit[i][j][k] = 20000;
		}
	}
	cout << bfs(sx, sy);
	//print();
	return 0;
}