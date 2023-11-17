#include <iostream>
using namespace std;

int n, m, s;
char map[200][200];
char tmp[200][200];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << map[i][j];
		cout << '\n';
	}
}

void change(int x, int y) {
	tmp[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
		tmp[nx][ny] = '.';
	}
}

void func() {
	//print();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = 'O';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'O') {
				change(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	if (s % 2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << 'O';
			cout << '\n';
		}
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < s / 2; i++) {
		func();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << map[i][j];
		cout << '\n';
	}
	return 0;
}