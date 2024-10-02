#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9 + 7

int n, m, s, e;
vector<pair<int, int>> v[1001];
int path[1001];
int dist[1001];


void dijkstra() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (x == e) break;
		if (cost > dist[x]) continue;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int n_cost = cost + v[x][i].second;
			if (n_cost >= dist[y]) continue;
			else {
				path[y] = x;
				dist[y] = n_cost;
				pq.push({ -n_cost, y });
			}			
		}
	}
	int idx = e;
	vector<int> res;
	while (s != idx) {
		res.push_back(idx);
		idx = path[idx];
	}
	res.push_back(s);
	cout << dist[e] << '\n' << res.size() << '\n';
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back({ y ,cost });
	}
	cin >> s >> e;
	dijkstra();
	return 0;
}