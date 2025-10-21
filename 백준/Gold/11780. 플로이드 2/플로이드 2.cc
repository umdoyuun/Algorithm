#include <iostream>
using namespace std;
#define MAX 1e9

int n, m;
int dist[101][101];
int path[101][101];
int cnt[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		if (dist[x][y] > c) {
			dist[x][y] = c;
			path[x][y] = y;
			cnt[x][y] = 1;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
					cnt[i][j] = cnt[i][k] + cnt[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == MAX) {
				cout << 0;
			}
			else {
				cout << dist[i][j];
			}
			if (j < n) cout << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt[i][j]) {
				cout << cnt[i][j] + 1 << ' ' << i;
				int x = i;
				while (x != j && x != 0) {
					cout << ' ' << path[x][j];
					x = path[x][j];
				}
			}
			else {
				cout << 0;
			}
			cout << '\n';
		}
	}
	return 0;
}