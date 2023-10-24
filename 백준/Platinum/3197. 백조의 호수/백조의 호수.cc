#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
char map[1501][1501];
bool visit[1501][1501];
string str;
vector<pair<int, int>> v;
queue<pair<int, int>> water;
queue<pair<int, int>> c_q;
int result;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void print() {
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << "w_siz : " << water.size() << '\n';
}

int bfs() {
	int cnt = 0;
	queue<pair<int, int>> q, next_q;
	q.push({ v[0].first, v[0].second });
	visit[v[0].first][v[0].second] = true;
	while (1) {
		//print();
		while (!q.empty()) {
			int ax = q.front().first;
			int ay = q.front().second;
			q.pop();
			if (ax == v[1].first && ay == v[1].second) return cnt;
			for (int i = 0; i < 4; i++) {
				int nx = ax + dx[i];
				int ny = ay + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (visit[nx][ny]) continue;
				visit[nx][ny] = true;
				if (map[nx][ny] == '.' || map[nx][ny] == 'L') {
					q.push({ nx, ny });
				}
				else {
					next_q.push({ nx, ny });
				}
			}
		}
		q = next_q;
		c_q = queue<pair<int, int>>();
		c_q = water;
		water = queue<pair<int, int>>();
		while(!c_q.empty()) {
			int bx = c_q.front().first;
			int by = c_q.front().second;
			c_q.pop();
			for (int j = 0; j < 4; j++) {
				int nnx = bx + dx[j];
				int nny = by + dy[j];
				if (nnx < 0 || nnx >= n || nny < 0 || nny >= m) continue;
				if (map[nnx][nny] == 'X') {
					map[nnx][nny] = '.';
					water.push({ nnx, nny });
				}
			}
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'L') {
				v.push_back({ i,j });
				water.push({ i,j });
			}
			else if (map[i][j] == '.')
				water.push({ i,j });
		}
	}
	cout << bfs();
	return 0;
}