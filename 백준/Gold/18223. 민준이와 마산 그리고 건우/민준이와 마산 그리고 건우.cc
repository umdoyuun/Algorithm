#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1e9

int n, m, p;
vector<pair<int, int>> v[5001];
int dist[5001];

void dijkstra(int s) {
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
		for (pair<int, int> next : v[x]) {
			int y = next.first;
			int ncost = cost + next.second;
			if (dist[y] > ncost) {
				dist[y] = ncost;
				pq.push({ -ncost, y });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> p;
	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back({ y, cost });
		v[y].push_back({ x, cost });
	}
	dijkstra(1);
	int tar = dist[n];
	int tmp = dist[p];
	dijkstra(p);
	if (tar == tmp + dist[n]) {
		cout << "SAVE HIM\n";
	}
	else {
		cout << "GOOD BYE\n";
	}
	return 0;
}