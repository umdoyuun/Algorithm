#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>v[50001];
int n, m;
int dist[50001];

void dijkstra() {
	priority_queue<pair<int, int>> q;
	q.push({ 0, 1 });
	dist[1] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		int c = -q.top().first;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int nc = v[x][i].second + c;
			if (nc < dist[y]) {
				dist[y] = nc;
				q.push({ -nc, y });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ y,c });
		v[y].push_back({ x,c });
	}
	dijkstra();
	cout << dist[n];
	return 0;
}