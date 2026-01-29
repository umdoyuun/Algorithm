#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, s, cnt, res;
vector<pair<int, int>> v[100001];
bool visit[100001];

void init() {
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
	cnt = 0;
	res = 0;
	memset(visit, 0, sizeof(visit));
}

void bfs() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;		
		pq.pop();
		if (visit[x]) continue;
		visit[x] = true;
		res = cost;
		cnt++;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int nc = v[x][i].second;
			if (visit[y]) continue;
			pq.push({ -cost - nc, y });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> s;
		init();
		for (int i = 0; i < m; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			v[y].push_back({ x, c });
		}
		bfs();
		cout << cnt << ' ' << res << '\n';
	}
	return 0;
}