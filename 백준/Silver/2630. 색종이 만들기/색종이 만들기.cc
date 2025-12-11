#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int graph[129][129];
int n, blue, white;
bool B, W;

void dfs(int x, int y, int size) {
	B = true;
	W = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] == 0) B = false;
			if (graph[i][j] == 1) W = false;
		}
	}
	if (B) {
		blue++;
		return;
	}
	if (W) {
		white++;
		return;
	}
	dfs(x, y, size / 2);
	dfs(x + size / 2, y, size / 2);
	dfs(x, y + size / 2, size / 2);
	dfs(x + size / 2, y + size / 2, size / 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, 0, n);
	cout << white << '\n' << blue << '\n';
	return 0;
}
