#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, k, cnt;
};

int n, res, s, e;
int map[101][101];
node q[100001];
bool visit[101][101][6002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void make_island(int sx, int sy, int k) {
	q[e++] = { sx, sy, k, 0 };
	map[sx][sy] = k;
	while (s < e) {
		int x = q[s].x;
		int y = q[s].y;
		int k = q[s].k;		
		s++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] != 1) continue;
			map[nx][ny] = k;
			q[e++] = { nx, ny, k, 0 };
		}
	}
}

int bfs() {
	s = 0;
	while (s < e) {
		int x = q[s].x;
		int y = q[s].y;
		int k = q[s].k;
		int cnt = q[s].cnt;
		s++;
		if (map[x][y] != k && map[x][y]) {
			return cnt - 1;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == k || visit[nx][ny][k]) continue;
			visit[nx][ny][k] = true;
			q[e++] = { nx, ny, k, cnt + 1 };
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int l = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				make_island(i, j, l);
				l++;
			}
		}
	}
	cout << bfs();
	
	return 0;
}