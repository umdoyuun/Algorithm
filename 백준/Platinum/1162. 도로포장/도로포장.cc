#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
long long dist[10001][21];
long long res = 1e11;
vector<pair<int, int>> v[10001];

void dijkstra() {
	priority_queue < pair<long long, pair<int, int>>> pq;
	pq.push({ 0, {0, 1} });
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int cnt = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (x == n) res = min(res, cost);
		if (dist[x][cnt] < cost) continue;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			long long n_cost = cost + v[x][i].second;
			if (n_cost < dist[y][cnt]) {
				dist[y][cnt] = n_cost;
				pq.push({ -n_cost, {cnt, y} });
			}
			if (cnt + 1 <= k && dist[y][cnt + 1] > cost) {
				dist[y][cnt + 1] = cost;
				pq.push({ -cost, {cnt + 1, y} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (register int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ y, c });
		v[y].push_back({ x, c });
	}
	for (register int i = 1; i <= n; i++) {
		for (register int j = 0; j <= k; j++) {
			dist[i][j] = 1e11;
		}
	}
	dijkstra();
	cout << res << '\n';
	return 0;
}