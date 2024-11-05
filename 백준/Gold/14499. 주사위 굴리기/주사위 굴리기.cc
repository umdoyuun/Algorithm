#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, m, sx, sy, k;
int graph[21][21];
int command[1001];
int dice[6];

void func() {
	int x = sx;
	int y = sy;
	int tmp;
	for (int i = 0; i < k; i++) {
		switch (command[i]) {
		case 1://동
			if (y == m - 1) break;
			y += 1;
			tmp = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[2];
			dice[2] = tmp;
			if (graph[x][y] == 0) {
				graph[x][y] = dice[0];
			}
			else {
				dice[0] = graph[x][y];
				graph[x][y] = 0;
			}
			cout << dice[5] << '\n';
			break;
		case 2:
			if (y == 0) break;
			y -= 1;
			tmp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[1];
			dice[1] = tmp;
			if (graph[x][y] == 0) {
				graph[x][y] = dice[0];
			}
			else {
				dice[0] = graph[x][y];
				graph[x][y] = 0;
			}
			cout << dice[5] << '\n';
			break;
		case 3:
			if (x == 0) break;
			x -= 1;
			tmp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[4];
			dice[4] = tmp;
			if (graph[x][y] == 0) {
				graph[x][y] = dice[0];
			}
			else {
				dice[0] = graph[x][y];
				graph[x][y] = 0;
			}
			cout << dice[5] << '\n';
			break;
		case 4:
			if (x == n - 1) break;
			x += 1;
			tmp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[3];
			dice[3] = tmp;
			if (graph[x][y] == 0) {
				graph[x][y] = dice[0];
			}
			else {
				dice[0] = graph[x][y];
				graph[x][y] = 0;
			}
			cout << dice[5] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> sx >> sy >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> command[i];
	}
	func();
	return 0;
}