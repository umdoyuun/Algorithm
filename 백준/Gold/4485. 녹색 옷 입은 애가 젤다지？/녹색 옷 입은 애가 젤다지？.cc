#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n;
int arr[126][126];
bool visit[126][126];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool init() {
	memset(visit, 0, sizeof(visit));
	cin >> n;
	if (!n) return false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	return true;
}

int bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -arr[0][0], {0, 0} });
	visit[0][0] = true;
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = -pq.top().first;
		if (x == n - 1 && y == n - 1) {
			return cost;
		}
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncost = cost + arr[nx][ny];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visit[nx][ny]) continue;
			visit[nx][ny] = true;
			pq.push({ -ncost, {nx, ny} });
		}
	}
	return visit[n - 1][n - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 0;
	while (1) {
		if (!init()) {
			break;
		}
		int res = bfs();
		cout << "Problem " << ++T << ": " << res << '\n';
	}
	return 0;
}