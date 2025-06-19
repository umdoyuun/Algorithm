#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, is_cnt = 1, max_level;
char Map[51][51];
int map[51][51];
bool visit[51][51];
int cnt[1000];
int par[1000];
int level[1000];

int dx[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };


pair<int, int> edge[1000];

void make_island(int sx, int sy, int id) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	int ex = sx, ey = sy;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (ex < x) {
			ex = x;
			ey = y;
		}
		else if (ex == x && ey < y) {
			ex = x;
			ey = y;
		}
		map[x][y] = id;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || Map[nx][ny] == '.') continue;
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	edge[id] = { ex, ey };
}

int check(int id) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ edge[id].first, edge[id].second });
	int par_id = -1;
	int px = -1, py = -1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) return -1;
			if (visit[nx][ny] || map[nx][ny] == id) continue;
			if (map[nx][ny] > 0) {
				if (par_id == -1) {
					par_id = map[nx][ny];
					px = nx;
					py = ny;
					continue;
				}
				else if (par_id == map[nx][ny]) continue;
				else {
					if (px < nx) {
						px = nx;
						py = ny;
						par_id = map[nx][ny];
					}
					else if (px == nx && py < ny) {
						px = nx;
						py = ny;
						par_id = map[nx][ny];
					}
					continue;
				}
			}
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	return par_id;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j] == 'x' && !visit[i][j]) {
				make_island(i, j, is_cnt);
				cnt[0]++;
				is_cnt++;
			}
		}
	}
	if (cnt[0] == 0) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i < is_cnt; i++) {
		int par_id = check(i);
		if (par_id != -1) {
			par[i] = par_id;
			int j = i;
			while (par_id != 0) {
				int tmp = level[par_id];
				level[par_id] = max(level[j] + 1, level[par_id]);
				max_level = max(max_level, level[par_id]);
				cnt[tmp]--;
				cnt[level[par_id]]++;
				j = par_id;
				par_id = par[par_id];
			}
		}
	}
	for (int i = 0; i <= max_level; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}