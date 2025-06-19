#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int n, m, k;
char map[101][101];
bool visit[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void crash(int h, int cnt) {
	if (cnt % 2 == 0) {
		for (int i = 0; i < m; i++) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = m - 1; i >= 0; i--) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				break;
			}
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visit[nx][ny] || map[nx][ny] == '.') continue;
		dfs(nx, ny);
	}
	return;
}

void move() {
	int h = 0;
	vector<pair<int, int>> v;
	bool c = false;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'x' && visit[i][j] == false) {
				v.push_back({ i,j });
				map[i][j] = '.';
				c = true;
			}
		}
	}
	if (c) {
		while (1) {
			bool flag = false;
			for (int i = 0; i < v.size(); i++) {
				int x = v[i].first;
				int y = v[i].second;
				if (x + h + 1 >= n || map[x+h+1][y] == 'x') {
					flag = true;
					break;
				}
			}
			if (flag) break;
			h++;
		}
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first + h;
			int y = v[i].second;
			map[x][y] = 'x';
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int j;
		cin >> j;
		crash(n - j, i);
		memset(visit, false, sizeof(visit));
		for (int k = 0; k < m; k++) {
			if (!visit[n - 1][k] && map[n - 1][k] == 'x')
				dfs(n - 1, k);
		}
		move();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}