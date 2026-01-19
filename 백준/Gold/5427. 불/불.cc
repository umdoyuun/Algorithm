#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, sx, sy;
char graph[1001][1001];
int fire_visit[1001][1001];
bool visit[1001][1001];

queue<pair<int, int>> fire;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void fire_move() {
	while (!fire.empty()) {
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] == '#' || fire_visit[nx][ny] >= 0) continue;
			fire_visit[nx][ny] = fire_visit[x][y] + 1;
			fire.push({ nx, ny });
		}
	}
}

void init() {
	memset(visit, 0, sizeof(visit));
	memset(fire_visit, -1, sizeof(fire_visit));
	fire = queue<pair<int, int>>();
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == '@') {
				sx = i;
				sy = j;
			}
			else if (graph[i][j] == '*') {
				fire.push({ i, j });
				fire_visit[i][j] = 0;
			}
		}
	}
	fire_move();
}

int bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {sx, sy} });
	visit[sx][sy] = true;
	
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				return cnt + 1;
			}
			
			if (graph[nx][ny] != '#' && !visit[nx][ny] && 
			    (fire_visit[nx][ny] == -1 || fire_visit[nx][ny] > cnt + 1)) {
				visit[nx][ny] = true;
				q.push({ cnt + 1, {nx, ny} });
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		init();
		int ret = bfs();
		if (ret) cout << ret << '\n';
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}