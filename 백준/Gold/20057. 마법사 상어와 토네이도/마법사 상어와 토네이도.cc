#include <iostream>
using namespace std;

int n, res;
int map[500][500];
bool visit[500][500];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void calc(int x, int y, int dir) {
	visit[x][y] = true;
	if (map[x][y] == 0) return;
	pair<int, int> front = { x + dx[dir], y + dy[dir] };
	pair<int, int> back = { x - dx[dir], y - dy[dir] };
	int sum = 0;
	for (int i = 1; i <= 3; i += 2) {
		int fx = front.first + dx[(dir + i) % 4];
		int fy = front.second + dy[(dir + i) % 4];

		int nx = x + dx[(dir + i) % 4];
		int ny = y + dy[(dir + i) % 4];

		int nx2 = x + dx[(dir + i) % 4] * 2;
		int ny2 = y + dy[(dir + i) % 4] * 2;

		int bx = back.first + dx[(dir + i) % 4];
		int by = back.second + dy[(dir + i) % 4];

		if (fx < 0 || fy < 0 || fx >= n || fy >= n) res += map[x][y] / 10;
		else map[fx][fy] += map[x][y] / 10;
		sum += map[x][y] / 10;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) res += map[x][y] * 7 / 100;
		else map[nx][ny] += map[x][y] * 7 / 100;
		sum += map[x][y] * 7 / 100;
		if (nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= n) res += map[x][y] / 50;
		else map[nx2][ny2] += map[x][y] / 50;
		sum += map[x][y] / 50;
		if (bx < 0 || by < 0 || bx >= n || by >= n) res += map[x][y] / 100;
		else map[bx][by] += map[x][y] / 100;
		sum += map[x][y] / 100;
	}

	int fx2 = x + dx[dir] * 2;
	int fy2 = y + dy[dir] * 2;
	if (fx2 < 0 || fy2 < 0 || fx2 >= n || fy2 >= n) res += map[x][y] / 20;
	else map[fx2][fy2] += map[x][y] / 20;
	sum += map[x][y] / 20;
	if (front.first < 0 || front.second < 0 || front.first >= n || front.second >= n) res += map[x][y] - sum;
	else map[front.first][front.second] += map[x][y] - sum;

	map[x][y] = 0;
}

void tonado() {
	int x = n / 2, y = n / 2;
	int dir = 3;
	visit[x][y] = true;
	while (x != 0 || y != 0) {
		int nd = (dir + 1) % 4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if (!visit[nx][ny]) {
			dir = nd;
			calc(nx, ny, dir);
			x = nx;
			y = ny;
		}
		else {
			nx = x + dx[dir];
			ny = y + dy[dir];
			calc(nx, ny, dir);
			x = nx;
			y = ny;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (register int i = 0; i < n; i++) {
		for (register int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	tonado();
	cout << res << '\n';
	return 0;
}