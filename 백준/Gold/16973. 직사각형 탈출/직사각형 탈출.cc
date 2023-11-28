#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

struct node {
	int X, Y, Cnt;
};
int n, m, h, w, sr, sc, fr, fc;
int map[1005][1005];
bool visit[1005][1005];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool check(int x, int y, int dir)
{
	if (dir == 0)
	{
		int ny = y + w - 1;
		for (int i = x; i < x + h; i++)
			if (map[i][ny] == 1) return false;
	}
	else if (dir == 1)
	{
		for (int i = x; i < x + h; i++)
			if (map[i][y] == 1) return false;
	}
	else if (dir == 2)
	{
		int nx = x + h - 1;
		for (int i = y; i < y + w; i++)
			if (map[nx][i] == 1) return false;
	}
	else if (dir == 3)
	{
		for (int i = y; i < y + w; i++)
			if (map[x][i] == 1) return false;
	}
	return true;
}

int bfs() {
	queue<node> q;
	q.push({ sr, sc, 0 });
	visit[sr][sc] = true;
	while (!q.empty()) {
		int x = q.front().X;
		int y = q.front().Y;
		int cnt = q.front().Cnt;
		q.pop();
		if(x == fr && y == fc){
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx + h - 1 > n || ny + w - 1> m) continue;
			if (visit[nx][ny]) continue;
			if (nx + h - 1 > n || ny + w - 1 > m) continue;
			if (check(nx, ny, i)) {
				visit[nx][ny] = true;
				q.push({ nx, ny, cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> h >> w >> sr >> sc >> fr >> fc;
	cout << bfs();
	return 0;
}