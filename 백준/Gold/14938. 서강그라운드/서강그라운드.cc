#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1e9

int n, m, r, res;
int dist[101][101];
int items[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = MAX;
		}
	}
	for (int i = 0; i < r; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		dist[x][y] = c;
		dist[y][x] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) {
				cnt += items[j];
			}
		}
		res = max(res, cnt);
	}
	cout << res << '\n';
	return 0;
}