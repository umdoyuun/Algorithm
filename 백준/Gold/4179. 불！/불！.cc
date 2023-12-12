#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, cnt;
};


int n, m;
char map[1001][1001];
int dist[1001][1001];
int fire[1001][1001];
bool visit[1001][1001];
queue<node> fq;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void print() {
	cout << "fire\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << fire[i][j];
		}
		cout << '\n';
	}
	cout << "dist\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j];
		}
		cout << '\n';
	}
}

void f_bfs() {
	while (!fq.empty()) {
		int x = fq.front().x;
		int y = fq.front().y;
		int cnt = fq.front().cnt;
		fq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == '#') continue;
			if (fire[nx][ny] > cnt + 1) {
				fire[nx][ny] = cnt + 1;
				fq.push({ nx,ny,cnt + 1 });
			}
		}
	}
}

int bfs(int sx, int sy) {
	queue<node> q;
	q.push({ sx, sy, 0 });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
			return cnt + 1;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || map[nx][ny] == '#') continue;
			if (fire[nx][ny] > cnt + 1) {
				dist[nx][ny] = cnt + 1;
				visit[nx][ny] = true;
				q.push({ nx, ny, cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			fire[i][j] = 0x7fffffff;
			if (map[i][j] == 'J') {
				sx = i;
				sy = j;
			}
			if (map[i][j] == 'F') {
				fq.push({ i, j, 0 });
				fire[i][j] = 0;
			}
		}
	}
	f_bfs();
	int result = bfs(sx, sy);
	//print();
	if (result == -1) cout << "IMPOSSIBLE\n";
	else cout << result;
	return 0;
}