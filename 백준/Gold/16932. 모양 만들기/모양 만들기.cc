#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
bool visit[1001][1001];
int map[1001][1001];
int p[1001][1001];
int result, p_cnt;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void check(int sx, int sy) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> tmp_q;
	tmp_q.push({ sx, sy });
	q.push({ sx, sy });
	visit[sx][sy] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || map[nx][ny] != 1) continue;
			tmp_q.push({ nx, ny });
			cnt++;
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}		
	}
	p_cnt++;
	while (!tmp_q.empty()) {
		int x = tmp_q.front().first;
		int y = tmp_q.front().second;
		tmp_q.pop();
		map[x][y] = cnt;
		p[x][y] = p_cnt;
	}
}

int func(int x, int y) {
	int cnt = 1;
	int pp[4]= {0,};
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
		for (int j = 0; j < i; j++) {
			if (pp[j] == p[nx][ny]) {
				cnt -= map[nx][ny];
				break;
			}
		}
		cnt += map[nx][ny];
		pp[i] = p[nx][ny];
	}
	return cnt;
}

void fill() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !visit[i][j])
				check(i, j);
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
			cin >> map[i][j];
		}
	}
	fill();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				result = max(func(i, j), result);
			}
		}
	}
	//print();
	/*if (result == 0) {
		if (map[0][0] == 0)
			result = 1;
		else
			result = map[0][0];
	}*/
	cout << result;
	return 0;
}