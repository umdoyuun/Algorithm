#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
#define max(a,b) a>b ? a:b

int n, m, x;
int s, e, c;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> reverse_graph[1001];
int dist[1001];
int reverse_dist[1001];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, x });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();
		if (cur_cost > dist[cur]) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int next_cost = cur_cost + graph[cur][i].second;
			if (next_cost < dist[next]) {
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
	pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();
		if (cur_cost > reverse_dist[cur]) continue;
		for (int i = 0; i < reverse_graph[cur].size(); i++) {
			int next = reverse_graph[cur][i].first;
			int next_cost = cur_cost + reverse_graph[cur][i].second;
			if (next_cost < reverse_dist[next]) {
				reverse_dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
}

int main() {
	int result = 0;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		graph[s].push_back({ e,c });
		reverse_graph[e].push_back({ s,c });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		reverse_dist[i] = INF;
	}
	dijkstra();

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		result = max(result, dist[i] + reverse_dist[i]);
	}
	cout << result;
	return 0;
}