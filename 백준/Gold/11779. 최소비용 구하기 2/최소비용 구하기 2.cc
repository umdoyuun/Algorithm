#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1e9

int n, m, s, e, cnt;
vector<pair<int, int>> v[1000];
int dist[1001];
int path[1001];

int dat[1000];
void dijkstra() {
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (x == e) break;
		for (pair<int, int> next : v[x]) {
			int y = next.first;
			int ncost = next.second + cost;
			if (dist[y] <= ncost) continue;
			dist[y] = ncost;
			path[y] = x;
			pq.push({ -ncost, y });
		}
	}
}

void path_trace() {
	int cur = e;
	dat[cnt++] = cur;
	while (cur != s) {
		cur = path[cur];
		dat[cnt++] = cur;
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
		v[x].push_back({y, cost});
	}
	cin >> s >> e;
	dijkstra();
	path_trace();
	cout << dist[e] << '\n' << cnt << '\n';
	for (int i = cnt - 1; i >= 0; i--) {
		cout << dat[i] << ' ';
	}
	return 0;
}