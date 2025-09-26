#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, cnt;
vector<int> v[100001];
int visit[100001];

void bfs() {
	queue<int> q;
	q.push(s);
	visit[s] = ++cnt;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		sort(v[x].begin(), v[x].end(), greater<int>());
		for (int y : v[x]) {
			if (visit[y]) continue;
			visit[y] = ++cnt;
			q.push(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x);
		v[x].push_back(y);
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
	return 0;
}