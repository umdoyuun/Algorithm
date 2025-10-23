#include <iostream>
using namespace std;
#define MAX 1e9

int n, res;
int cost[21][21], dist[21][21];
bool visit[21][21];
bool check = true;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
			if (i < j) {
				res += cost[i][j];
			}
			dist[i][j] = cost[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visit[i][j] || visit[i][k] || visit[k][j]) continue;
				if (i == k || k == j) continue;
				if (dist[i][j] >= dist[i][k] + dist[k][j]) {
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						check = false;
					}
					visit[i][j] = true;
					visit[j][i] = true;
					res -= dist[i][j];
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	if (check) {
		cout << res;
	}
	else {
		cout << -1;
	}
	return 0;
}