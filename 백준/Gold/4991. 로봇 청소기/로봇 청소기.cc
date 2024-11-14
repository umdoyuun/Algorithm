#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
#include<string>
using namespace std;

int n, m, sx, sy, d_cnt = 0;
int result = 0;
string str;
bool visit[20][20][1 << 10];
char map[20][20];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void init() {
	result = 0;
	d_cnt = 0;
	memset(visit, 0, sizeof(visit));
}

void print(int x, int y, int cnt, int d) {
	cout << '\n' << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == x && j == y) {
				cout << "a";
			}
			else {
				cout << map[i][j];
			}
		}
		cout << '\n';
	}
	cout << "남은 더러운 장소: " << d << " 이동횟수: " << cnt << '\n';
}

int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({ sx, sy, 0, 0 });
	visit[sx][sy][0] = true;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		int d = get<3>(q.front());
		q.pop();
		//print(x, y, cnt, d);
		if (d == (1 << d_cnt) - 1) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nd = d;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == -1) continue;
			if (map[nx][ny] > 0) {
				nd |= (1 << (map[nx][ny] - 1));
			}
			if (!visit[nx][ny][d]) {
				visit[nx][ny][d] = true;
				q.push({ nx,ny,cnt + 1, nd });
			}
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		init();
		cin >> m >> n;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == 'o') sx = i, sy = j, map[i][j] = 0;
				else if (str[j] == '*') map[i][j] = ++d_cnt;
				else if (str[j] == 'x') map[i][j] = -1;
				else map[i][j] = 0;
			}
		}
		result = bfs();
		cout << result << '\n';
	}
	return 0;
}