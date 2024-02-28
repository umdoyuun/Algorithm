#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 0x7fffffff

struct node {
	int x, y, cost;
};

int n, m;

vector<node> v;
long long dist[501];
bool flag;

void bellmanford() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = v[j].x;
			int y = v[j].y;
			int cost = v[j].cost;
			if (dist[x] == INF) continue;
			if (dist[y] > dist[x] + cost) {
				dist[y] = dist[x] + cost;
				if (i == n - 1) {
					flag = true;
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v.push_back({ x,y,c });
	}
	bellmanford();
	if (flag) {
		cout << "-1\n";
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF)
				cout << "-1\n";
			else
				cout << dist[i] << '\n';
		}
	}
	return 0;
}