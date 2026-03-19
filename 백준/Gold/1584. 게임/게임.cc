#include <iostream>
#include <queue>
using namespace std;

const int mx = 2550;

class node {
public:
	int x, y, cnt;

	bool operator < (const node& other) const {
		return cnt > other.cnt;
	}
};

int coord[501][501];
int dist[501][501];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			dist[i][j] = mx;
		}
	}
	priority_queue<node> pq;
	pq.push({ 0, 0, 0 });
	dist[0][0] = 0;
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cnt = pq.top().cnt;
		if (x == 500 && y == 500) return cnt;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > 500 || ny > 500 || coord[nx][ny] == -1) continue;
			if (dist[nx][ny] <= dist[x][y] + coord[nx][ny]) continue;
			dist[nx][ny] = dist[x][y] + coord[nx][ny];
			pq.push({ nx, ny, dist[nx][ny]});
		}
	}
	return - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, x1, x2, y1, y2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				coord[i][j] = 1;
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				coord[i][j] = -1;
			}
		}
	}
	int res = bfs();
	cout << res;
	return 0;
}