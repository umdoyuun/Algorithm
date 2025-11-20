#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, d;
int dist[10001];
vector<pair<int, int>> v[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d;
	for (int i = 1; i <= d; i++) {
		dist[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back({ y, cost });
	}
	for (int i = 0; i <= d; i++) {
		if (i > 0) {
			dist[i] = min(dist[i], dist[i - 1] + 1);
		}
		for (auto x : v[i]) {
			dist[x.first] = min(dist[x.first], dist[i] + x.second);
		}
	}
	cout << dist[d];
	return 0;
}