#include <iostream>
#include <queue>
using namespace std;

int n, m, a, b, k;
int arr[501][501];
bool visit[501][501];

struct node{
	int x, y, cnt;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool check(int x, int y, int l) {
	if (x + a - 1 > n || y + b - 1 > m || x <= 0 || y <= 0 || visit[x][y]) return false;
	for (int i = x; i <= x + a - 1; i++) {
		for (int j = y; j <= y + b - 1; j++) {
			if (arr[i][j] == -1) return false;
		}
	}
	return true;
}

int bfs(int sx, int sy, int ex, int ey) {
	queue<node> q;
	q.push({ sx, sy, 1 });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		if (x == ex && y == ey) {
			return cnt - 1;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny, cnt + 1)) {
				visit[nx][ny] = true;
				q.push({ nx, ny ,cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = -1;
	}
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	int ret = bfs(sx, sy, ex, ey);
	cout << ret << '\n';
	return 0;
}