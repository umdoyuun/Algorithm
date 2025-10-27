#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1e9

int n;
int dist[51][51];
int cnt[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			dist[i][j] = MAX;
		}
	}
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == -1) {
			break;
		}
		if (x >= 0 && y >= 0) {
			dist[x][y] = 1;
			dist[y][x] = 1;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int dat[51] = { 0, };
	int res = MAX, idx = 0;
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
		for (int j = 1; j <= n; j++) {
			cnt[i] = max(dist[i][j], cnt[i]);
		}
		if (cnt[i] == res) {
			dat[idx++] = i;
		}
		else if (cnt[i] < res) {
			res = cnt[i];
			idx = 0;
			dat[idx++] = i;

		}
	}
	cout << res << ' ' << idx << '\n';
	for (int i = 0; i < idx; i++) {
		cout << dat[i] << ' ';
	}
	return 0;
}