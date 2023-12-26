#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[251][251];
bool visit[251][251];
int result[2];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	int s_cnt = 0, w_cnt = 0;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (map[x][y] == 'o') {
			s_cnt++;
		}
		else if (map[x][y] == 'v')
			w_cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || map[nx][ny] == '#') continue;
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	if (s_cnt > w_cnt) result[0] += s_cnt;
	else result[1] += w_cnt;
	//cout << "sheep : " << s_cnt << " / wolf : " << w_cnt << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '#' && !visit[i][j]) {
				//cout << i << ' ' << j << '\n';
				bfs(i, j);
			}
		}
	}
	cout << result[0] << ' ' << result[1] << '\n';
	return 0;
}