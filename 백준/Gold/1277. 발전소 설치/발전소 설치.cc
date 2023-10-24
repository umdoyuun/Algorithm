#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

struct node {
	int x, y;
};

int n, w;
double m;
vector<node> v;
vector<pair<int, double>> vv[1000];
double dist[1000];

double find_dist(int start, int end) {
	int x = v[start].x;
	int y = v[start].y;
	int x2 = v[end].x;
	int y2 = v[end].y;
	double cost = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
	return cost;
}

void dijkstra() {
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
	pq.push({ 0, 0 });
	dist[0] = 0;
	while (!pq.empty()) {
		double cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		for(int i = 0; i < vv[x].size(); i++) {
			int y = vv[x][i].first;
			double ncost = vv[x][i].second;
			if (dist[y] > cost + ncost) {
				dist[y] = cost + ncost;
				pq.push({ cost + ncost, y });
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> w >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			double cost = find_dist(i, j);
			if (cost <= m) {
				vv[i].push_back({ j, cost });
				vv[j].push_back({ i, cost });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		dist[i] = 123456789.0;
	}
	for (int i = 0; i < w; i++) {
		cin >> x >> y;
		vv[x - 1].push_back({ y - 1, 0 });
		vv[y - 1].push_back({ x - 1, 0 });
	}
	dijkstra();
	int result = (int)(dist[n - 1] * 1000);
	cout << result;
	return 0;
}