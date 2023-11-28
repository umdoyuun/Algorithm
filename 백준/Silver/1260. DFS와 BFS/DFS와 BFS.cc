#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, V;
vector<int> v[1001];
bool visit[1001];

void dfs(int x) {
	visit[x] = true;
	cout << x << ' ';
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!visit[y])
			dfs(y);
	}
}

void bfs(int sx) {
	queue<int> q;
	visit[sx] = false;
	q.push(sx);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (visit[y]) {
				q.push(y);
				visit[y] = false;
			}
		}
	}
}

void Sort() {
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> V;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	Sort();
	dfs(V);
	cout << '\n';
	bfs(V);
	return 0;
}