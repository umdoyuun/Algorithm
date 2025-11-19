#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, vs, res = 1e9;
int graph[51][51];
int visit[51][51];
int tar;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> v;

pair<int, int> dat[11];

int bfs() {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		q.push(dat[i]);
		visit[dat[i].first][dat[i].second] = 1;
	}
	int ret = 1, cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visit[nx][ny] || graph[nx][ny] == 1) continue;
			if (graph[nx][ny] == 2) {
				visit[nx][ny] = visit[x][y] + 1;
				q.push({ nx, ny });
			}
			else {
				visit[nx][ny] = visit[x][y] + 1;
				ret = max(visit[nx][ny], ret);
				cnt++;
				q.push({ nx, ny });
			}
		}
	}
	if (cnt < tar) return 1e9;
	else return ret - 1;
}

void dfs(int idx, int s) {
	if (s == m) {
		res = min(bfs(), res);
		return;
	}
	for (int i = idx; i < vs; i++) {
		dat[s] = v[i];
		dfs(i + 1, s + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	tar = n * n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				v.push_back({ i, j });
				vs++;
			}
			if (graph[i][j]) {
				tar--;
			}
		}
	}
	dfs(0, 0);
	if (res == 1e9) res = -1;
	cout << res;
	return 0;
}