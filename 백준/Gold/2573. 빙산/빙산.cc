#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct XY {
	int x, y;
};
int n, m;
queue <XY> q;
queue<XY> tmp_q;
int map[301][301];
bool visit[301][301];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


void bfs() {
	tmp_q = queue<XY> ();
	int tmp_map[301][301] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (tmp_map[x][y] == 0) break;
			if (map[nx][ny] == 0) tmp_map[x][y]--;
		}
		if (map[x][y] > 0) tmp_q.push({ x,y });
	}
	q = tmp_q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			map[i][j] = tmp_map[i][j];
	}
}

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visit[nx][ny]) continue;
		if(map[nx][ny] > 0)
			dfs(nx, ny);
	}
}

bool check() {
	bool c = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) {
				c = false;
			}
		}
	}
	return c;
}

bool check2() {
	bool c = false;
	memset(visit, false, sizeof(visit));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0 && visit[i][j] == false) {
				cnt++;
				if (cnt > 1) c = true;
				dfs(i, j);
			}
		}
	}
	return c;
}

int func() {
	int cnt = 0;
	while (true) {
		if (check()) {
			return 0;
		}
		if (check2()) break;
		cnt++;
		bfs();
		//print();
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) q.push({ i,j });
		}
	}
	cout << func();
	return 0;
}