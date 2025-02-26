#include <iostream>
#include <queue>
using namespace std;
#define x first
#define y second

int n, m;
char arr[10][10];
bool visit[10][10][10][10];
pair<int, int> red, blue, goal;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct ball {
	int rx, ry, bx, by, cnt;
};

ball move(ball cur, int d) {
	int nrx = cur.rx;
	int nry = cur.ry;
	int nbx = cur.bx;
	int nby = cur.by;
	while (arr[nrx + dx[d]][nry + dy[d]] != '#' && arr[nrx][nry] != 'O') {
		nrx += dx[d];
		nry += dy[d];
	}
	while (arr[nbx + dx[d]][nby + dy[d]] != '#' && arr[nbx][nby] != 'O') {
		nbx += dx[d];
		nby += dy[d];
	}

	if (nrx == nbx && nry == nby) {
		switch (d) {
		case 0:
			if (cur.rx > cur.bx) {
				if (arr[nrx][nry] == 'O') {
					return { 0,0,0,0,0 };

				}
				else {
					nbx -= 1;
				}
			}
			else {
				if (arr[nrx][nry] == 'O') {
					return { -1, -1, -1, -1, -1 };

				}
				else {
					nrx -= 1;
				}
			}
			break;
		case 1:
			if (cur.ry > cur.by) {
				if (arr[nrx][nry] == 'O') {
					return { 0,0,0,0,0 };

				}
				nby -= 1;
			}
			else {
				if (arr[nrx][nry] == 'O') {
					return { -1, -1, -1, -1, -1 };

				}
				nry -= 1;
			}
			break;
		case 2:
			if (cur.rx < cur.bx) {
				if (arr[nrx][nry] == 'O') {
					return { 0,0,0,0,0 };
				}
				nbx += 1;
				break;
			}
			else {
				if (arr[nrx][nry] == 'O') {
					return { -1, -1, -1, -1, -1 };

				}
				nrx += 1;
			}
			break;
		case 3:
			if (cur.ry < cur.by) {
				if (arr[nrx][nry] == 'O') {
					return { -1, -1, -1, -1, -1 };

				}
				nby += 1;
			}
			else {
				if (arr[nrx][nry] == 'O') {
					return { 0,0,0,0,0 };
				}
				nry += 1;
			}
		}
	}
	return { nrx, nry, nbx, nby, cur.cnt + 1 };
}

int bfs() {
	queue< ball> q;
	q.push({ red.x, red.y, blue.x, blue.y, 0 });
	visit[red.x][red.y][blue.x][blue.y] = true;
	while (!q.empty()) {
		ball cur = q.front();
		if (cur.rx == goal.x && cur.ry == goal.y) {
			return cur.cnt;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			ball next = move(cur, i);
			if (next.cnt == -1) continue;
			if (next.rx < 0 || next.ry < 0 || next.rx > n || next.ry > m) continue;
			if (next.bx < 0 || next.by < 0 || next.bx > n || next.by > m) continue;
			if (visit[next.rx][next.ry][next.bx][next.by]) continue;
			visit[next.rx][next.ry][next.bx][next.by] = true;
			q.push({ next.rx,next.ry,next.bx,next.by, cur.cnt + 1 });
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
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				blue.x = i;
				blue.y = j;
			}
			else if (arr[i][j] == 'R') {
				red.x = i;
				red.y = j;
			}
			else if (arr[i][j] == 'O') {
				goal.x = i;
				goal.y = j;
			}
		}
	}
	cout << bfs();
	return 0;
}