#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int mx = 1e9;

int n, m, k, A, B;
vector<int> members;
vector<pair<int, int>> edges[1001];
int dist[1001];

int dijkstra(int s) {
	for (int i = 1; i <= m; i++) {
		dist[i] = mx;
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	int flag = 0;
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > dist[x]) continue;
		for (auto [y, nc] : edges[x]) {
			nc += cost;
			if (dist[y] == mx || dist[y] > nc) {
				dist[y] = nc;
				pq.push({ -nc, y });
			}
		}
	}
	if (dist[A] == mx) dist[A] = -1;
	if (dist[B] == mx) dist[B] = -1;
	return dist[A] + dist[B];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> A >> B;
	int x, y, c;
	for (int i = 0; i < n; i++) {		
		cin >> x;
		members.push_back(x);
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> c;
		edges[x].push_back({ y, c });
		edges[y].push_back({ x, c });
	}
	int res = 0;
	for (auto x : members) {
		res += dijkstra(x);
	}
	cout << res << '\n';
	return 0;
}