#include <iostream>
#include <queue>
using namespace std;

int n, m, res;
int arr[105][105];
bool visit[105][105];

int dx[6] = { 0, 0, 1, 1, -1, -1 };
int dy[2][6] = { {1, -1, -1, 0, -1, 0}, {1, -1, 0, 1, 0, 1} };

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[x % 2][i];
			if (nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1 || visit[nx][ny]) continue;
			if (arr[nx][ny]) {
				res++;
				continue;
			}
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i <= n + 1; i++) {		
		if (!arr[i][0] && !visit[i][0]) {
			bfs(i, 0);
		}
		else if (!arr[i][m + 1] && !visit[i][m + 1]) {
			bfs(i, m + 1);
		}
	}
	for (int j = 0; j <= m + 1; j++) {
		if (!arr[0][j] && !visit[0][j]) {
			bfs(0, j);
		}
		else if (!arr[n + 1][j] && !visit[n + 1][j]) {
			bfs(n + 1, j);
		}
	}
	cout << res;
	return 0;
}