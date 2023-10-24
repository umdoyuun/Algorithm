#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1000][1000];
int visit[1000][1000];
int result;

int dx[4] = { -1, 0, 1, 0 }; //0: up, 1: right, 2: down, 3: left
int dy[4] = { 0, 1, 0, -1 };


void dfs(int x, int y) {
	char cmd = map[x][y];
	visit[x][y] = 1;
	int nx = x + dx[map[x][y]];
	int ny = y + dy[map[x][y]];
	if (visit[nx][ny] == 1) result++;
	if (visit[nx][ny] == 0) dfs(nx, ny);
	visit[x][y] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char cmd;
			cin >> cmd;
			switch (cmd) {
			case 'U':
				map[i][j] = 0;
				break;
			case 'R':
				map[i][j] = 1;
				break;
			case 'D':
				map[i][j] = 2;
				break;
			case 'L':
				map[i][j] = 3;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				dfs(i, j);
			}
		}
	}
	cout << result;
	return 0;
}