#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int mx = 1e9;
vector<pair<int, int>> v[1001];
int dist[1001];
int path[1001];

void distInit(int n) {
	for (int i = 2; i <= n; i++) {
		dist[i] = mx;
	}
}

int makePath(int e) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	distInit(e);
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (x == e) return cost;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int ncost = cost + v[x][i].second;
			if (dist[y] > ncost) {
				dist[y] = ncost;
				path[y] = x;
				pq.push({ -ncost, y });
			}
		}
	}
	return 0;
}

int dijkstra(int e, int px, int py) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	distInit(e);
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (e == x) return cost;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int ncost = cost + v[x][i].second;
			if (x == px && y == py) continue;
			if (dist[y] > ncost) {
				dist[y] = ncost;
				pq.push({ -ncost, y });
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, res = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back({ y, cost });
		v[y].push_back({ x, cost });
	}
	res = makePath(n);
	for (int i = n; i != 1; i = path[i]) {
		res = max(res, dijkstra(n, path[i], i));
	}
	cout << res << '\n';
	return 0;
}