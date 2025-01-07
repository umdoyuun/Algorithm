#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int graph[9][9];
int c_graph[9][9];
bool visit[9][9];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int result = 0;

void bfs() {
	int c_c_graph[9][9];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c_c_graph[i][j] = c_graph[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_c_graph[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (c_c_graph[nx][ny] == 0) {
					c_c_graph[nx][ny] = 2;
					q.push({ nx, ny });
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_c_graph[i][j] == 0)
				cnt++;
		}
	}
	result = max(result, cnt);
	return;
}

void func(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_graph[i][j] == 0) {
				c_graph[i][j] = 1;
				func(cnt + 1);
				c_graph[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				for (int k = 0; k < n; k++) {
					for (int h = 0; h < m; h++) {
						c_graph[k][h] = graph[k][h];
					}
				}
				c_graph[i][j] = 1;
				func(1);
				c_graph[i][j] = 0;
			}
		}
	}
	cout << result;
	return 0;
}
