#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[50][50];
bool visit[50][50][1 << 6];
int result = 123456789;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int sx, sy;

struct xy {
	int x, y, key, cnt;
};

void bfs() {
	queue<xy> q;
	q.push({ sx, sy, 0, 0 });
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int key = q.front().key;
		int cnt = q.front().cnt;
		q.pop();
		if (map[x][y] == '1') {
			result = min(result, cnt);
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == '#') continue;
			if (visit[nx][ny][key]) continue;
			if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
				int nkey = key | (1 << (map[nx][ny] - 'a'));
				if (visit[nx][ny][nkey]) continue;
				q.push({ nx, ny, nkey, cnt + 1 });
				visit[nx][ny][nkey] = true;
			}
			else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
				int c = key & (1 << (map[nx][ny] - 'A'));
				if (c == 0) continue;
				q.push({ nx, ny, key, cnt + 1 });
				visit[nx][ny][key] = true;
			}
			else {
				q.push({ nx, ny, key, cnt + 1 });
				visit[nx][ny][key] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				sx = i;
				sy = j;
			}
		}
	}
	bfs();
	if (result == 123456789) result = -1;
	cout << result;
	return 0;
}