#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long MAX = 1e18 + 1;

int n, m;
vector<pair<int, long long>> v[100001];
int visiable[100001];
long long dist[100001];

void bfs() {
	priority_queue<pair<long long, int>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		int x = pq.top().second;
		long long cost = -pq.top().first;
		pq.pop();
		if (dist[x] < cost) continue;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			long long nc = cost + v[x][i].second;
			if (visiable[y] && y != (n - 1)) continue;
			if (dist[y] <= nc) continue;
			dist[y] = nc;
			pq.push({ -nc, y });
		}
	}	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> visiable[i];
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ y, c });
		v[y].push_back({ x, c });
	}
	for (int i = 0; i < n; i++) {
		dist[i] = MAX;
	}
	bfs();
	if (dist[n - 1] == MAX) dist[n - 1] = -1;
	cout << dist[n - 1];
	return 0;
}