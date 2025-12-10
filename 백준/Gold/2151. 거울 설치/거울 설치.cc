#include <iostream>
#include <queue>
using namespace std;

int n;
int sx, sy, ex, ey;
char coord[51][51];
bool visit[51][51][4];

class node {
public:
	int x, y, cnt, dir;
	bool operator< (const node &other) const {
		return cnt > other.cnt;
	}
};

int dx[4] = { 1, -1, 0, 0 }; // 하 상 우 좌
int dy[4] = { 0, 0, 1, -1 };

int func() {
	priority_queue<node> pq;
	coord[sx][sy] = '.';
	for (int i = 0; i < 4; i++) {
		pq.push({ sx, sy, 0, i });
		visit[sx][sy][i] = true;
	}
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		if (cur.x == ex && cur.y == ey) {
			return cur.cnt;
		}
		int nx = cur.x + dx[cur.dir];
		int ny = cur.y + dy[cur.dir];
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
		if (coord[nx][ny] == '*') {
			continue;
		}
		if (coord[nx][ny] == '!') {
			if (cur.dir < 2) {
				
				for (int i = 2; i < 4; i++) {
					if (!visit[nx][ny][i]) {
						pq.push({ nx, ny, cur.cnt + 1, i });
						visit[nx][ny][i] = true;
					}
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					if (!visit[nx][ny][i]) {
						pq.push({ nx, ny, cur.cnt + 1, i });
						visit[nx][ny][i] = true;
					}
				}
			}
		}
		if (visit[nx][ny][cur.dir]) continue;
		pq.push({ nx, ny, cur.cnt, cur.dir });
		visit[nx][ny][cur.dir] = true;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> coord[i][j];
			if (coord[i][j] == '#') {
				if (sx) {
					ex = i;
					ey = j;
				}
				else {
					sx = i;
					sy = j;
				}
			}
		}
	}
	int res = func();
	cout << res;
	return 0;
}