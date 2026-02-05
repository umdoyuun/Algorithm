#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e8;

int n, m;
int dist[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			dist[i][j] = MAX;
		}
	}
	for (int i = 1; i < n; i++) {
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
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] << '\n';
	}
	return 0;
}