#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool visit[100][100][100];
int map[100][100];
int result;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, int layer) {
	visit[x][y][layer] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visit[nx][ny][layer]) continue;
		if (map[nx][ny] <= layer) continue;
		dfs(nx, ny, layer);
	}
	return;
}

void func() {
	for (int layer = 0; layer <= 100; layer++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j][layer] && map[i][j] > layer) {
					dfs(i, j, layer);
					cnt++;
				}
			}
		}
		result = max(cnt, result);
	}
	return;
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
	func();
	cout << result;
	return 0;
}