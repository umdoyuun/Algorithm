#include <iostream>
#include <queue>
using namespace std;

int map[19][19];
int win = 0, rx, ry;

int dx[4] = { 0, -1, 1, 1 };
int dy[4] = { 1, 1, 1, 0 };

bool check(int x, int y, int t) {
	int cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y;
		if (map[x - dx[i]][y - dy[i]] == t) continue;
		cnt = 1;
		for (int j = 0; j < 5; j++) {
			nx += dx[i];
			ny += dy[i];
			if (nx < 0 || ny < 0 || nx >= 19 || ny >= 19) continue;
			if (map[nx][ny] != t) break;
			cnt++;
		}
		if (cnt == 5) return true;
	}
	return false;
}

void find() {
	for (register int i = 0; i < 19; i++) {
		for (register int j = 0; j < 19; j++) {
			if (map[i][j] != 0) {
				if (check(i, j, map[i][j])) {
					win = map[i][j];
					rx = i + 1;
					ry = j + 1;
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (register int i = 0; i < 19; i++) {
		for (register int j = 0; j < 19; j++) {
			cin >> map[i][j];
		}
	}
	find();
	if (win) cout << win << '\n' << rx << ' ' << ry << '\n';
	else cout << win << '\n';
	return 0;
}