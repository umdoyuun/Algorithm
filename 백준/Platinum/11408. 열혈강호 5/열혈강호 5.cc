#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 805
#define INF 1e9

int n, m, res, cnt;
vector<int> v[MAX];
int c[MAX][MAX], f[MAX][MAX], d[MAX][MAX];
int p[MAX], dist[MAX];
bool inq[MAX];

void mcmf() {
	while (1) {
		queue<int> q;
		fill(dist, dist + MAX, INF);
		memset(p, -1, sizeof(p));
		memset(inq, false, sizeof(inq));
		dist[0] = 0;
		q.push(0);
		inq[0] = true;
		p[0] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			inq[x] = false;
			for (auto y : v[x]) {
				if (c[x][y] - f[x][y] > 0 && dist[y] > dist[x] + d[x][y]) {
					dist[y] = dist[x] + d[x][y];
					p[y] = x;
					if (!inq[y]) {
						inq[y] = true;
						q.push(y);
					}
				}
			}
		}
		if (p[804] == -1) break;
		int flow = INF;
		for (int i = 804; i != 0; i = p[i]) {
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		}
		for (int i = 804; i != 0; i = p[i]) {
			res += flow * d[p[i]][i];
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v[i].push_back(0);
		v[0].push_back(i);
		c[0][i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		c[400 + i][804] = 1;
		v[804].push_back(i + 400);
		v[i + 400].push_back(804);
	}

	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int x, cost;
			cin >> x >> cost;
			v[i].push_back(x + 400);
			v[x + 400].push_back(i);
			d[i][x + 400] = cost;
			d[x + 400][i] = -cost;
			c[i][x + 400] = 1;
		}
	}
	mcmf();
	cout << cnt << '\n' << res << '\n';
	return 0;
}