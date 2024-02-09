#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define Min 1
#define Max 1e9

int n, m, s, e;
int result;
vector<pair<int, int>> v[10001];

bool check(int w) {
	queue<int> q;
	q.push(s);
	bool visit[10001] = { false, };
	visit[s] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == e) return true;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int cost = v[x][i].second;
			if (visit[y]) continue;
			if (cost < w) continue;
			q.push(y);
			visit[y] = true;
		}
	}
	return false;
}

void func() {
	int left = Min, right = Max;
	while (left <= right) {
		int mid = left + ((right - left) / 2);
		if (check(mid)) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({ y, w });
		v[y].push_back({ x, w });
	}
	cin >> s >> e;
	func();
	cout << result << '\n';
	return 0;
}