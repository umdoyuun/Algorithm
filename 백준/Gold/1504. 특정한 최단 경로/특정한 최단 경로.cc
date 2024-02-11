#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e9

bool flag1;
bool flag2;
int n, m;
vector<pair<int, int>> v[801];

int dijkstra(int s, int e) {
	if (s == e) return 0;
	int dist[801];
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int w = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (w != dist[x]) continue;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int n_w = w + v[x][i].second;
			if (n_w < dist[y]) {
				dist[y] = n_w;
				pq.push({ -n_w, y });
			}
		}
	}
	if (dist[e] == INF) return -1;
	return dist[e];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({ y, w });
		v[y].push_back({ x, w });
	}
	int v1, v2, result = -1;
	cin >> v1 >> v2;
	int v1v2dist = dijkstra(v1, v2);
	int sv1 = dijkstra(1, v1);
	int sv2 = dijkstra(1, v2);
	int v1e = dijkstra(v1, n);
	int v2e = dijkstra(v2, n);
	if (sv1 != -1 && v2e != -1) {
		result = sv1 + v2e + v1v2dist;
	}
	if (sv2 != -1 && v1e != -1) {
		int tmp = sv2 + v1e + v1v2dist;
		if (result != -1) {
			if (result > tmp) result = tmp;
		}
	}

	cout << result;
	return 0;
}