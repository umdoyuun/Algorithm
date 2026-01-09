#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int mx = 1e9;

int n, m, k;
int dist[101][101];
int sum[101];

void init() {
	memset(sum, 0, sizeof(sum));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = mx;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		dist[x][y] = c;
		dist[y][x] = c;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		init();
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		int mn_sum = mx, res = 0;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			for (int j = 1; j <= n; j++) {
				sum[j] += dist[x][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			if (sum[i] < mn_sum) {
				res = i;
				mn_sum = sum[i];
			}
		}
		cout << res << '\n';
	}
	return 0;
}