#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, res;
int graph[10][10];

bool check(int x) {
	int tar = sqrt(x);
	if (x == pow(tar, 2)) {
		return true;
	}
	else return false;
}

void calc(int x, int y, int w, int h) {
	int num = graph[x][y];
	while (true) {
		if (check(num)) res = max(res, num);
		x += w;
		y += h;
		if (x < 0 || y < 0 || x >= n || y >= m) break;
		if (w == 0 && h == 0) break;
		num *= 10;
		num += graph[x][y];
	}
	if (check(num)) res = max(res, num);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			graph[i][j] = x - '0';
		}
	}
	res = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int w = -n + 1; w < n; w++) {
				for (int h = -m + 1; h < m; h++) {
					calc(i, j, w, h);
				}
			}
		}
	}
	cout << res << '\n';
	return 0;
}