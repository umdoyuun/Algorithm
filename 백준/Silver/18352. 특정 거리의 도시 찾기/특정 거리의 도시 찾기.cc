#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, s;
vector<int> v[300001];
int dist[300001];
vector<int> result;

void bfs() {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (dist[x] == k) result.push_back(x);
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (dist[y] != 0 || y == s) continue;
			dist[y] = dist[x] + 1;
			q.push(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> s;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	bfs();
	sort(result.begin(), result.end());
	if (result.size() != 0) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
	else {
		cout << "-1\n";
	}
	return 0;
}